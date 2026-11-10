#ifndef POKEPLATINUM_OV59_021D2A2C_H
#define POKEPLATINUM_OV59_021D2A2C_H

#include "record_mixed_rng.h"

u32 RecordMixedRNG_GetEntrySize(RecordMixedRNG *param0);
void *RecordMixedRNG_GetPlayerOverrideEntry(RecordMixedRNG *param0);
void RecordMixedRNG_MergeReceivedQueueEntries(int param0, int param1, RecordMixedRNG *param2, const void **param3);

#endif // POKEPLATINUM_OV59_021D2A2C_H
