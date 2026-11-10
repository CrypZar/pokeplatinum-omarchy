#ifndef POKEPLATINUM_TV_BROADCAST_H
#define POKEPLATINUM_TV_BROADCAST_H

#include "struct_decls/tv_broadcast.h"
#include "struct_defs/tv_amity_square_watch_data.h"
#include "struct_defs/tv_poffin_corner_data.h"
#include "struct_defs/tv_battle_tower_corner_outcome.h"
#include "struct_defs/struct_0202E808.h"
#include "struct_defs/tv_battle_frontier_frontline_news_single_data.h"
#include "struct_defs/struct_0202E81C.h"
#include "struct_defs/struct_0202E828.h"
#include "struct_defs/struct_0202E834.h"
#include "struct_defs/tv.h"
#include "struct_defs/tv_segment_contest_hall_showcased_pokemon.h"

int TVBroadcast_SaveSize(void);
void TVBroadcast_Init(TVBroadcast *broadcast);
void TVBroadcast_ClearSavedSegments(TVBroadcast *broadcast);
void TVBroadcast_UpdateProgramTimeSlot(TVBroadcast *broadcast, int deltaMinutes, int currentMinute);
void TVBroadcast_ClearWatchProgress(TVBroadcast *broadcast);
void TVBroadcast_SetProgramFinished(TVBroadcast *broadcast, BOOL finished);
BOOL TVBroadcast_IsProgramFinished(const TVBroadcast *broadcast);
void TVBroadcast_SetPlayedSegment(TVBroadcast *broadcast, int segmentID);
BOOL TVBroadcast_IsPlayedSegment(const TVBroadcast *broadcast, int segmentID);
int TVBroadcast_CountPlayedSegments(const TVBroadcast *broadcast);
BOOL TVBroadcast_SaveSegmentData(TVBroadcast *broadcast, int param1, int param2, const u8 *param3);
const u16 *TVWifiEpisode_GetTrainerName(const TVWifiEpisode *param0);
int TVWifiEpisode_GetLanguage(const TVWifiEpisode *param0);
int TVWifiEpisode_GetGameVersion(const TVWifiEpisode *param0);
TVSegmentInstance *TVWifiEpisode_GetSegmentInstance(TVWifiEpisode *param0);
TVSegmentInstance *sub_0202E4D8(TVSegmentInstance *param0);
int TVSegmentInstance_GetSegmentID(const TVSegmentInstance *param0);
void TVSegmentInstance_IncrementPlayCount(TVSegmentInstance *param0);
void *TVSegmentInstance_GetData(TVSegmentInstance *param0);
int TVBroadcast_GetMatchingSegmentSlotIDs(const TVBroadcast *broadcast, int param1, int param2, BOOL param3, BOOL param4, u8 *param5);
BOOL TVBroadcast_CanSaveSegment(TVBroadcast *broadcast, int param1, int param2);
TVSegmentInstance *TVBroadcast_GetProgramSegment(TVBroadcast *broadcast, int param1, int param2);
TVWifiEpisode *TVBroadcast_GetWifiEpisode(TVBroadcast *broadcast, int param1, int param2);
BOOL TVBroadcast_IsLocalSegmentSlotID(int param0);
int TVBroadcast_MakeWifiEpisodeSlotID(int param0);
TVSegment_ContestHall_ShowcasedPokemon *TVBroadcast_GetShowcasedPokemon(TVBroadcast *broadcast);
TVAmitySquareWatchData *TVBroadcast_GetAmitySquareWatchData(TVBroadcast *broadcast);
TVPoffinCornerData *TVBroadcast_GetPoffinCornerData(TVBroadcast *broadcast);
TVBattleTowerCornerOutcome *TVBroadcast_GetBattleTowerCornerOutcome(TVBroadcast *broadcast);
UnkStruct_0202E808 *TVBroadcast_GetSafariGameData(TVBroadcast *broadcast);
TVBattleFrontierFrontlineNewsSingleData *TVBroadcast_GetBattleFrontierFrontlineNewsSingleData(TVBroadcast *broadcast);
UnkStruct_0202E81C *sub_0202E81C(TVBroadcast *broadcast);
TVBroadcast_BattlePointData *TVBroadcast_GetBattlePointData(TVBroadcast *broadcast);
TVBroadcast_GTSData *TVBroadcast_GetGTSData(TVBroadcast *broadcast);

#endif // POKEPLATINUM_TV_BROADCAST_H
