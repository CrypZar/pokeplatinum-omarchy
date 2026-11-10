#include "overlay059/mixed_records_payloads.h"

#include <nitro.h>
#include <string.h>

#include "struct_decls/tv_broadcast.h"
#include "struct_defs/dress_up_photo.h"
#include "struct_defs/image_clips.h"
#include "struct_defs/wifi_player_profile.h"

#include "overlay059/mixed_records_rng_queue.h"
#include "overlay059/wifi_tv_episodes.h"
#include "overlay059/struct_ov59_021D30E0.h"
#include "savedata/save_table.h"

#include "battle_tower_save.h"
#include "communication_information.h"
#include "communication_system.h"
#include "heap.h"
#include "rankings.h"
#include "record_mixed_rng.h"
#include "savedata.h"
#include "unk_020298BC.h"
#include "tv_broadcast.h"
#include "unk_02073700.h"

typedef struct {
    enum HeapID heapID;
    SaveData *saveData;
    int unk_08;
    int unk_0C;
    const void **unk_10;
    const void **unk_14;
} Overlay059MixedRecordsApplyContext;

typedef u32 (*Overlay059MixedRecordsPayloadSizeFunc)(SaveData *);
typedef void *(*Overlay059MixedRecordsBuildPayloadFunc)(SaveData *, enum HeapID heapID, u32);
typedef void (*Overlay059MixedRecordsApplyPayloadFunc)(const Overlay059MixedRecordsApplyContext *);

typedef struct {
    Overlay059MixedRecordsPayloadSizeFunc unk_00;
    Overlay059MixedRecordsBuildPayloadFunc unk_04;
    Overlay059MixedRecordsApplyPayloadFunc unk_08;
} Overlay059MixedRecordsDataAdapter;

static u32 Overlay059_GetMixedRecordsRNGPayloadSize(SaveData *saveData)
{
    RecordMixedRNG *v0 = SaveData_GetRecordMixedRNG(saveData);
    return RecordMixedRNG_GetEntrySize(v0);
}

static void *Overlay059_CreateMixedRecordsRNGPayload(SaveData *saveData, enum HeapID heapID, u32 param2)
{
    RecordMixedRNG *v0 = SaveData_GetRecordMixedRNG(saveData);
    void *v1 = Heap_AllocAtEnd(heapID, param2);

    MI_CpuCopyFast(RecordMixedRNG_GetPlayerOverrideEntry(v0), v1, param2);

    return v1;
}

static void Overlay059_ApplyMixedRecordsRNGPayload(const Overlay059MixedRecordsApplyContext *param0)
{
    RecordMixedRNG *v0 = SaveData_GetRecordMixedRNG(param0->saveData);
    RecordMixedRNG_MergeReceivedQueueEntries(param0->unk_08, param0->unk_0C, v0, param0->unk_10);
}

static u32 Overlay059_GetDressUpPhotoPayloadSize(SaveData *saveData)
{
    ImageClips *imageClips = SaveData_GetImageClips(saveData);
    return DressUpPhoto_Size();
}

static void *Overlay059_CreateDressUpPhotoPayload(SaveData *saveData, enum HeapID heapID, u32 param2)
{
    DressUpPhoto *photo;
    ImageClips *imageClips = SaveData_GetImageClips(saveData);
    void *v2 = Heap_AllocAtEnd(heapID, param2);

    photo = ImageClips_GetDressUpPhoto(imageClips, 0);
    MI_CpuCopyFast(photo, v2, param2);

    return v2;
}

static void Overlay059_MergeReceivedDressUpPhotos(const Overlay059MixedRecordsApplyContext *param0)
{
    ImageClips *imageClips = SaveData_GetImageClips(param0->saveData);
    sub_0202A6A8(param0->unk_08, param0->unk_0C, imageClips, param0->unk_10);
}

static void Overlay059_ApplyTrainerSightingsEpisodePayload(const Overlay059MixedRecordsApplyContext *param0)
{
    TVBroadcast *broadcast = SaveData_GetTVBroadcast(param0->saveData);
    TVBroadcast_MergeTrainerSightingsWifiEpisodes(broadcast, param0->unk_08, param0->unk_0C, param0->unk_10, param0->unk_14);
}

static void Overlay059_ApplyRecordsEpisodePayload(const Overlay059MixedRecordsApplyContext *param0)
{
    TVBroadcast *broadcast = SaveData_GetTVBroadcast(param0->saveData);
    TVBroadcast_MergeRecordsWifiEpisodes(broadcast, param0->unk_08, param0->unk_0C, param0->unk_10, param0->unk_14);
}

static void Overlay059_ApplyInterviewsEpisodePayload(const Overlay059MixedRecordsApplyContext *param0)
{
    TVBroadcast *broadcast = SaveData_GetTVBroadcast(param0->saveData);
    TVBroadcast_MergeInterviewsWifiEpisodes(broadcast, param0->unk_08, param0->unk_0C, param0->unk_10, param0->unk_14);
}

static void *Overlay059_CreateRankingEntriesPayload(SaveData *saveData, enum HeapID heapID, u32 param2)
{
    return SaveData_GetRankingEntries(saveData, heapID);
}

static void Overlay059_ApplyReceivedRankingEntries(const Overlay059MixedRecordsApplyContext *param0)
{
    Rankings *v0 = SaveData_GetRankings(param0->saveData);

    SaveData_UpdateRankings(param0->saveData, param0->unk_0C, param0->unk_08, param0->unk_10, param0->heapID);
}

static void *Overlay059_CreateWifiPlayerProfilePayload(SaveData *saveData, enum HeapID heapID, u32 param2)
{
    WifiPlayerProfile *profile = Heap_AllocAtEnd(heapID, param2);
    MI_CpuClear8(profile, param2);
    sub_02073700(saveData, 0, profile);

    return profile;
}

static void Overlay059_NoOpWifiPlayerProfileApply(const Overlay059MixedRecordsApplyContext *param0)
{
    return;
}

static const Overlay059MixedRecordsDataAdapter Overlay059MixedRecordsDataAdapters[] = {
    { Overlay059_GetMixedRecordsRNGPayloadSize, Overlay059_CreateMixedRecordsRNGPayload, Overlay059_ApplyMixedRecordsRNGPayload },
    { Overlay059_GetDressUpPhotoPayloadSize, Overlay059_CreateDressUpPhotoPayload, Overlay059_MergeReceivedDressUpPhotos },
    { (Overlay059MixedRecordsPayloadSizeFunc)TVWifiEpisode_GetTrainerSightingsBatchSize, (Overlay059MixedRecordsBuildPayloadFunc)TVWifiEpisode_CreateFilteredTrainerSightingsBatch, NULL },
    { (Overlay059MixedRecordsPayloadSizeFunc)TVWifiEpisode_GetRecordsBatchSize, (Overlay059MixedRecordsBuildPayloadFunc)TVWifiEpisode_CreateFilteredRecordsBatch, NULL },
    { (Overlay059MixedRecordsPayloadSizeFunc)TVWifiEpisode_GetInterviewsBatchSize, (Overlay059MixedRecordsBuildPayloadFunc)TVWifiEpisode_CreateFilteredInterviewsBatch, NULL },
    { (Overlay059MixedRecordsPayloadSizeFunc)RankingsEntries_Size, (Overlay059MixedRecordsBuildPayloadFunc)Overlay059_CreateRankingEntriesPayload, Overlay059_ApplyReceivedRankingEntries },
    { (Overlay059MixedRecordsPayloadSizeFunc)WifiPlayerProfile_Size, (Overlay059MixedRecordsBuildPayloadFunc)Overlay059_CreateWifiPlayerProfilePayload, Overlay059_NoOpWifiPlayerProfileApply },
    { (Overlay059MixedRecordsPayloadSizeFunc)TVWifiEpisode_GetTrainerSightingsBatchSize, (Overlay059MixedRecordsBuildPayloadFunc)TVWifiEpisode_CreateTrainerSightingsBatch, Overlay059_ApplyTrainerSightingsEpisodePayload },
    { (Overlay059MixedRecordsPayloadSizeFunc)TVWifiEpisode_GetRecordsBatchSize, (Overlay059MixedRecordsBuildPayloadFunc)TVWifiEpisode_CreateRecordsBatch, Overlay059_ApplyRecordsEpisodePayload },
    { (Overlay059MixedRecordsPayloadSizeFunc)TVWifiEpisode_GetInterviewsBatchSize, (Overlay059MixedRecordsBuildPayloadFunc)TVWifiEpisode_CreateInterviewsBatch, Overlay059_ApplyInterviewsEpisodePayload }
};

void ov59_021D30E0(SaveData *saveData, UnkStruct_ov59_021D30E0 *param1)
{
    u32 v0;
    void *v1;
    int v2, v3;
    u32 v4 = 3000;
    u8 *v5 = param1->unk_00;
    const Overlay059MixedRecordsDataAdapter *v6 = Overlay059MixedRecordsDataAdapters;

    v3 = NELEMS(Overlay059MixedRecordsDataAdapters);

    for (v2 = 0; v2 < v3; v2++) {
        v0 = v6[v2].unk_00(saveData);
        v1 = v6[v2].unk_04(saveData, HEAP_ID_51, v0);

        GF_ASSERT(v4 > v0);

        MI_CpuCopyFast(v1, v5, v0);
        Heap_Free(v1);

        v5 += v0;
        v4 -= v0;
    }
}

void ov59_021D313C(SaveData *saveData, const UnkStruct_ov59_021D30E0 *param1)
{
    Overlay059MixedRecordsApplyContext v0;
    u32 v1;
    u32 v2 = 0;
    u32 v3 = 3000;
    int i, v5, v6;
    const void *v7[5];
    const void *v8[5];
    u32 v9[4 - 2 + 1];

    v0.heapID = HEAP_ID_51;
    v0.saveData = saveData;
    v0.unk_0C = CommSys_CurNetId();
    v0.unk_08 = 5;
    v0.unk_10 = v7;
    v0.unk_14 = v8;

    v9[2 - 2] = 0;
    v9[3 - 2] = 0;
    v9[4 - 2] = 0;

    for (i = 0; i < 2; i++) {
        v9[2 - 2] += Overlay059MixedRecordsDataAdapters[i].unk_00(saveData);
    }

    for (i = 0; i < 3; i++) {
        v9[3 - 2] += Overlay059MixedRecordsDataAdapters[i].unk_00(saveData);
    }

    for (i = 0; i < 4; i++) {
        v9[4 - 2] += Overlay059MixedRecordsDataAdapters[i].unk_00(saveData);
    }

    for (i = 0; i < NELEMS(Overlay059MixedRecordsDataAdapters); i++) {
        v1 = Overlay059MixedRecordsDataAdapters[i].unk_00(saveData);
        GF_ASSERT(v3 > v1);

        for (v5 = 0; v5 < 5; v5++) {
            if (CommInfo_TrainerInfo(v5) != NULL) {
                v0.unk_10[v5] = &(param1[v5].unk_00[v2]);
            } else {
                v0.unk_10[v5] = NULL;
            }
        }

        switch (i) {
        case 7:
        case 8:
        case 9:
            for (v6 = 0; v6 < 5; v6++) {
                if (CommInfo_TrainerInfo(v6) != NULL) {
                    v0.unk_14[v6] = &(param1[v6].unk_00[v9[i - 7]]);
                } else {
                    v0.unk_14[v6] = NULL;
                }
            }
            break;
        }

        if (Overlay059MixedRecordsDataAdapters[i].unk_08 != NULL) {
            Overlay059MixedRecordsDataAdapters[i].unk_08(&v0);
        }

        v2 += v1;
        v3 -= v1;
    }

    TVBroadcast *broadcast = SaveData_GetTVBroadcast(saveData);
    TVBroadcast_ClearSavedSegments(broadcast);
    TVBroadcast_ClearWatchProgress(broadcast);
}
