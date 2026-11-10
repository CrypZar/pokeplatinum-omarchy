#ifndef POKEPLATINUM_OVERLAY059_APP_ARGS_H
#define POKEPLATINUM_OVERLAY059_APP_ARGS_H

#include "struct_decls/struct_0205C22C_decl.h"

#include "game_options.h"
#include "game_records.h"
#include "journal.h"
#include "savedata.h"

typedef struct {
    SaveData *saveData;
    UnkStruct_0205C22C *unk_04;
    Options *options;
    GameRecords *records;
    JournalEntry *journalEntry;
} Overlay059AppArgs;

#endif // POKEPLATINUM_OVERLAY059_APP_ARGS_H
