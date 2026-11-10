#ifndef POKEPLATINUM_OV59_021D2B44_H
#define POKEPLATINUM_OV59_021D2B44_H

#include "struct_decls/tv_broadcast.h"
#include "struct_defs/tv.h"

#include "savedata.h"

u32 TVWifiEpisode_GetInterviewsBatchSize(const SaveData *saveData);
u32 TVWifiEpisode_GetTrainerSightingsBatchSize(const SaveData *saveData);
u32 TVWifiEpisode_GetRecordsBatchSize(const SaveData *saveData);
TVWifiEpisode *TVWifiEpisode_CreateFilteredInterviewsBatch(SaveData *saveData, enum HeapID heapID, u32 param2);
TVWifiEpisode *TVWifiEpisode_CreateFilteredTrainerSightingsBatch(SaveData *saveData, enum HeapID heapID, u32 param2);
TVWifiEpisode *TVWifiEpisode_CreateFilteredRecordsBatch(SaveData *saveData, enum HeapID heapID, u32 param2);
TVWifiEpisode *TVWifiEpisode_CreateInterviewsBatch(SaveData *saveData, enum HeapID heapID, u32 param2);
TVWifiEpisode *TVWifiEpisode_CreateTrainerSightingsBatch(SaveData *saveData, enum HeapID heapID, u32 param2);
TVWifiEpisode *TVWifiEpisode_CreateRecordsBatch(SaveData *saveData, enum HeapID heapID, u32 param2);
void TVBroadcast_MergeTrainerSightingsWifiEpisodes(TVBroadcast *broadcast, int param1, int param2, const void **param3, const void **param4);
void TVBroadcast_MergeRecordsWifiEpisodes(TVBroadcast *broadcast, int param1, int param2, const void **param3, const void **param4);
void TVBroadcast_MergeInterviewsWifiEpisodes(TVBroadcast *broadcast, int param1, int param2, const void **param3, const void **param4);

#endif // POKEPLATINUM_OV59_021D2B44_H
