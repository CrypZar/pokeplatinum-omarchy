#ifndef POKEPLATINUM_OVERLAY059_MIXED_RECORDS_RNG_QUEUE_H
#define POKEPLATINUM_OVERLAY059_MIXED_RECORDS_RNG_QUEUE_H

#include "record_mixed_rng.h"

u32 RecordMixedRNG_GetEntrySize(RecordMixedRNG *param0);
void *RecordMixedRNG_GetPlayerOverrideEntry(RecordMixedRNG *param0);
void RecordMixedRNG_MergeReceivedQueueEntries(int param0, int param1, RecordMixedRNG *param2, const void **param3);

#endif // POKEPLATINUM_OVERLAY059_MIXED_RECORDS_RNG_QUEUE_H
