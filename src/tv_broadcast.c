#include "tv_broadcast.h"

#include <nitro.h>
#include <string.h>

#include "constants/tv_broadcast.h"

#include "struct_defs/tv_amity_square_watch_data.h"
#include "struct_defs/tv_poffin_corner_data.h"
#include "struct_defs/tv_battle_tower_corner_outcome.h"
#include "struct_defs/tv_safari_game_data.h"
#include "struct_defs/tv_battle_frontier_frontline_news_single_data.h"
#include "struct_defs/tv_battle_frontier_frontline_news_multi_data.h"
#include "struct_defs/tv_battle_points_news_data.h"
#include "struct_defs/tv_global_trade_news_data.h"
#include "struct_defs/tv.h"
#include "struct_defs/tv_segment_contest_hall_showcased_pokemon.h"

#include "inlines.h"
#include "rtc.h"
#include "savedata.h"

static void TVBroadcast_ClearPlayedSegments(TVBroadcast *broadcast);
static TVSegmentInstance *TVBroadcast_GetProgramSegmentSlots(TVBroadcast *broadcast, int param1);

int TVBroadcast_SaveSize(void)
{
    return sizeof(TVBroadcast);
}

void TVBroadcast_Init(TVBroadcast *broadcast)
{
    MI_CpuClearFast(broadcast, sizeof(TVBroadcast));
    SaveData_SetChecksum(SAVE_TABLE_ENTRY_TV_BROADCAST);
}

void TVBroadcast_ClearSavedSegments(TVBroadcast *broadcast)
{
    MI_CpuClearFast(broadcast->unk_0C, sizeof(TVSegmentInstance) * 4);
    MI_CpuClearFast(broadcast->unk_C4, sizeof(TVSegmentInstance) * 4);
    MI_CpuClearFast(broadcast->unk_17C, sizeof(TVSegmentInstance) * 4);

    TVBroadcast_ClearWatchProgress(broadcast);
    SaveData_SetChecksum(SAVE_TABLE_ENTRY_TV_BROADCAST);
}

void TVBroadcast_UpdateProgramTimeSlot(TVBroadcast *broadcast, int deltaMinutes, int currentMinute)
{
    int i;

    if (broadcast->timeSlotMinutesRemaining > deltaMinutes) {
        broadcast->timeSlotMinutesRemaining -= deltaMinutes;
    } else {
        broadcast->timeSlotMinutesRemaining = 15 - currentMinute % 15;

        if (broadcast->timeSlotMinutesRemaining == 0) {
            broadcast->timeSlotMinutesRemaining = 15;
        }

        broadcast->programFinished = FALSE;

        for (i = 0; i < TV_BROADCAST_MAX_PLAYED_SEGMENTS; i++) {
            broadcast->playedSegments[i] = 0;
        }
    }

    SaveData_SetChecksum(SAVE_TABLE_ENTRY_TV_BROADCAST);
}

void TVBroadcast_ClearWatchProgress(TVBroadcast *broadcast)
{
    TVBroadcast_SetProgramFinished(broadcast, FALSE);
    TVBroadcast_ClearPlayedSegments(broadcast);
    SaveData_SetChecksum(SAVE_TABLE_ENTRY_TV_BROADCAST);
}

void TVBroadcast_SetProgramFinished(TVBroadcast *broadcast, BOOL finished)
{
    broadcast->programFinished = finished;
    SaveData_SetChecksum(SAVE_TABLE_ENTRY_TV_BROADCAST);
}

BOOL TVBroadcast_IsProgramFinished(const TVBroadcast *broadcast)
{
    return broadcast->programFinished;
}

void TVBroadcast_SetPlayedSegment(TVBroadcast *broadcast, int segmentID)
{
    int i;

    for (i = 0; i < TV_BROADCAST_MAX_PLAYED_SEGMENTS; i++) {
        if (broadcast->playedSegments[i] == NULL) {
            broadcast->playedSegments[i] = segmentID;
            SaveData_SetChecksum(SAVE_TABLE_ENTRY_TV_BROADCAST);
            return;
        }
    }

    GF_ASSERT(FALSE);

    SaveData_SetChecksum(SAVE_TABLE_ENTRY_TV_BROADCAST);
}

static void TVBroadcast_ClearPlayedSegments(TVBroadcast *broadcast)
{
    int i;

    for (i = 0; i < TV_BROADCAST_MAX_PLAYED_SEGMENTS; i++) {
        broadcast->playedSegments[i] = 0;
    }

    SaveData_SetChecksum(SAVE_TABLE_ENTRY_TV_BROADCAST);
}

BOOL TVBroadcast_IsPlayedSegment(const TVBroadcast *broadcast, int segmentID)
{
    int i;

    for (i = 0; i < TV_BROADCAST_MAX_PLAYED_SEGMENTS; i++) {
        if (broadcast->playedSegments[i] == segmentID) {
            return TRUE;
        }
    }

    return FALSE;
}

int TVBroadcast_CountPlayedSegments(const TVBroadcast *broadcast)
{
    int i, playedCount;

    for (i = 0, playedCount = 0; i < TV_BROADCAST_MAX_PLAYED_SEGMENTS; i++) {
        if (broadcast->playedSegments[i] != 0) {
            playedCount++;
        }
    }

    return playedCount;
}

static void TVSegmentInstance_SetContents(TVSegmentInstance *param0, int segmentID, const u8 *param2)
{
    RTCDate time;
    GetCurrentDate(&time);

    param0->timestamp = Date_Encode(&time);
    param0->segmentID = segmentID;
    param0->timesPlayed = 0;

    MI_CpuCopyFast(param2, param0->segment, 40);
    SaveData_SetChecksum(SAVE_TABLE_ENTRY_TV_BROADCAST);
}

BOOL TVBroadcast_SaveSegmentData(TVBroadcast *broadcast, int param1, int param2, const u8 *param3)
{
    int i;
    TVSegmentInstance *v1 = TVBroadcast_GetProgramSegmentSlots(broadcast, param1);

    for (i = 0; i < 4; i++) {
        if (v1[i].segmentID == param2) {
            if (v1[i].timesPlayed >= 3) {
                TVSegmentInstance_SetContents(&v1[i], param2, param3);
                return 1;
            }

            return 0;
        }
    }

    for (i = 0; i < 4; i++) {
        if (v1[i].segmentID == 0) {
            TVSegmentInstance_SetContents(&v1[i], param2, param3);
            return 1;
        }
    }

    for (i = 0; i < 4; i++) {
        if (v1[i].timesPlayed >= 3) {
            TVSegmentInstance_SetContents(&v1[i], param2, param3);
            return 1;
        }
    }

    SaveData_SetChecksum(SAVE_TABLE_ENTRY_TV_BROADCAST);

    return 0;
}

const u16 *TVWifiEpisode_GetTrainerName(const TVWifiEpisode *param0)
{
    return param0->name;
}

int TVWifiEpisode_GetLanguage(const TVWifiEpisode *param0)
{
    return param0->language;
}

int TVWifiEpisode_GetGameVersion(const TVWifiEpisode *param0)
{
    return param0->gameVersion;
}

TVSegmentInstance *TVWifiEpisode_GetSegmentInstance(TVWifiEpisode *param0)
{
    return &param0->details;
}

TVSegmentInstance *sub_0202E4D8(TVSegmentInstance *param0)
{
    return param0;
}

static TVSegmentInstance *TVBroadcast_GetProgramSegmentSlots(TVBroadcast *broadcast, int param1)
{
    TVSegmentInstance *v0 = NULL;

    switch (param1) {
    case 1:
        v0 = broadcast->unk_17C;
        break;
    case 2:
        v0 = broadcast->unk_0C;
        break;
    case 3:
        v0 = broadcast->unk_C4;
        break;
    case 4:
    case 5:
        GF_ASSERT(FALSE);
    }

    return v0;
}

static TVWifiEpisode *TVBroadcast_GetWifiEpisodeSlots(TVBroadcast *broadcast, int param1)
{
    TVWifiEpisode *v0 = NULL;

    switch (param1) {
    case 2:
        v0 = broadcast->unk_234;
        break;
    case 3:
        v0 = broadcast->unk_684;
        break;
    case 1:
        v0 = broadcast->unk_8AC;
        break;
    case 4:
    case 5:
        GF_ASSERT(FALSE);
    }

    return v0;
}

int TVSegmentInstance_GetSegmentID(const TVSegmentInstance *param0)
{
    return param0->segmentID;
}

void TVSegmentInstance_IncrementPlayCount(TVSegmentInstance *param0)
{
    if (param0->timesPlayed < 3) {
        param0->timesPlayed++;
    }

    SaveData_SetChecksum(SAVE_TABLE_ENTRY_TV_BROADCAST);
}

void *TVSegmentInstance_GetData(TVSegmentInstance *param0)
{
    return param0->segment;
}

static int TVBroadcast_GetMatchingProgramSegmentSlotIDs(const TVSegmentInstance *param0, int param1, int param2, BOOL param3, u8 *param4)
{
    int v0, v1;

    for (v1 = 0, v0 = 0; v0 < param1; v0++) {
        if (param0[v0].segmentID == param2) {
            int v2 = param0[v0].timesPlayed;

            if (param3 && v2) {
                param4[v1] = v0 + 1;
                v1++;
            } else if (!param3 && (v2 == 0)) {
                param4[v1] = v0 + 1;
                v1++;
            }
        }
    }

    return v1;
}

static int TVBroadcast_GetMatchingWifiEpisodeSlotIDs(const TVWifiEpisode *param0, int param1, int param2, BOOL param3, u8 *param4)
{
    int v0, v1;

    for (v1 = 0, v0 = 0; v0 < param1; v0++) {
        int v2 = param0[v0].details.timesPlayed;

        if (param0[v0].details.segmentID == param2) {
            if (param3 && v2) {
                param4[v1] = TVBroadcast_MakeWifiEpisodeSlotID(v0 + 1);
                v1++;
            } else if (!param3 && (v2 == 0)) {
                param4[v1] = TVBroadcast_MakeWifiEpisodeSlotID(v0 + 1);
                v1++;
            }
        }
    }

    return v1;
}

int TVBroadcast_GetMatchingSegmentSlotIDs(const TVBroadcast *broadcast, int param1, int param2, BOOL param3, BOOL param4, u8 *param5)
{
    switch (param1) {
    case 2:
        if (param3) {
            return TVBroadcast_GetMatchingProgramSegmentSlotIDs(broadcast->unk_0C, 4, param2, param4, param5);
        } else {
            return TVBroadcast_GetMatchingWifiEpisodeSlotIDs(broadcast->unk_234, 16, param2, param4, param5);
        }
    case 3:
        if (param3) {
            return TVBroadcast_GetMatchingProgramSegmentSlotIDs(broadcast->unk_C4, 4, param2, param4, param5);
        } else {
            return TVBroadcast_GetMatchingWifiEpisodeSlotIDs(broadcast->unk_684, 8, param2, param4, param5);
        }
    case 1:
        if (param3) {
            return TVBroadcast_GetMatchingProgramSegmentSlotIDs(broadcast->unk_17C, 4, param2, param4, param5);
        } else {
            return TVBroadcast_GetMatchingWifiEpisodeSlotIDs(broadcast->unk_8AC, 8, param2, param4, param5);
        }
    case 4:
        return 0;
    case 5:
        return 0;
    }

    return 0;
}

BOOL TVBroadcast_CanSaveSegment(TVBroadcast *broadcast, int param1, int param2)
{
    int v0;
    int i;
    u8 v2[4];
    TVSegmentInstance *v3;

    MI_CpuClear8(v2, 4);

    v0 = TVBroadcast_GetMatchingSegmentSlotIDs(broadcast, param1, param2, 1, 0, v2);

    if (v0 != 0) {
        return 0;
    }

    v0 = TVBroadcast_GetMatchingSegmentSlotIDs(broadcast, param1, param2, 1, 1, v2);

    if (v0 != 0) {
        for (i = 0; i < 4 & v2[i] != 0; i++) {
            v3 = TVBroadcast_GetProgramSegment(broadcast, param1, v2[i]);

            if (v3->timesPlayed >= 3) {
                return 1;
            }
        }

        return 0;
    }

    for (i = 1; i <= 4; i++) {
        v3 = TVBroadcast_GetProgramSegment(broadcast, param1, i);

        if ((v3->segmentID == 0) || (v3->timesPlayed >= 3)) {
            return 1;
        }
    }

    return 0;
}

TVSegmentInstance *TVBroadcast_GetProgramSegment(TVBroadcast *broadcast, int param1, int param2)
{
    TVSegmentInstance *v0;

    GF_ASSERT(TVBroadcast_IsLocalSegmentSlotID(param2) == 1);

    param2 &= ~0x80;
    v0 = TVBroadcast_GetProgramSegmentSlots(broadcast, param1);

    return &v0[param2 - 1];
}

TVWifiEpisode *TVBroadcast_GetWifiEpisode(TVBroadcast *broadcast, int param1, int param2)
{
    TVWifiEpisode *v0;

    GF_ASSERT(TVBroadcast_IsLocalSegmentSlotID(param2) == 0);

    param2 &= ~0x80;
    v0 = TVBroadcast_GetWifiEpisodeSlots(broadcast, param1);

    return &v0[param2 - 1];
}

BOOL TVBroadcast_IsLocalSegmentSlotID(int param0)
{
    if (param0 & 0x80) {
        return 0;
    } else {
        return 1;
    }
}

int TVBroadcast_MakeWifiEpisodeSlotID(int param0)
{
    return param0 | 0x80;
}

TVSegment_ContestHall_ShowcasedPokemon *TVBroadcast_GetShowcasedPokemon(TVBroadcast *broadcast)
{
    return &broadcast->showcasedPokemon;
}

TVAmitySquareWatchData *TVBroadcast_GetAmitySquareWatchData(TVBroadcast *broadcast)
{
    return &broadcast->unk_ADE;
}

TVPoffinCornerData *TVBroadcast_GetPoffinCornerData(TVBroadcast *broadcast)
{
    return &broadcast->unk_B02;
}

TVBattleTowerCornerOutcome *TVBroadcast_GetBattleTowerCornerOutcome(TVBroadcast *broadcast)
{
    return &broadcast->unk_B04;
}

TVSafariGameData *TVBroadcast_GetSafariGameData(TVBroadcast *broadcast)
{
    return &broadcast->safariGame;
}

TVBattleFrontierFrontlineNewsSingleData *TVBroadcast_GetBattleFrontierFrontlineNewsSingleData(TVBroadcast *broadcast)
{
    return &broadcast->unk_B10;
}

TVBattleFrontierFrontlineNewsMultiData *TVBroadcast_GetBattleFrontierFrontlineNewsMultiData(TVBroadcast *broadcast)
{
    return &broadcast->unk_B2E;
}

TVBattlePointsNewsData *TVBroadcast_GetBattlePointData(TVBroadcast *broadcast)
{
    return &broadcast->battlePointData;
}

TVGlobalTradeNewsData *TVBroadcast_GetGTSData(TVBroadcast *broadcast)
{
    return &broadcast->gtsData;
}
