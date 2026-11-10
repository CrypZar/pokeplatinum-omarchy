#ifndef POKEPLATINUM_BATTLE_RECORDING_H
#define POKEPLATINUM_BATTLE_RECORDING_H

#include "struct_decls/struct_0202F298_decl.h"
#include "struct_decls/struct_0202F41C_decl.h"
#include "struct_decls/struct_02030A80_decl.h"
#include "struct_defs/battle_recording.h"

#include "field_battle_data_transfer.h"
#include "savedata.h"

int BattleRecording_SaveSize(void);
void BattleRecording_Init(BattleRecording *param0);
void BattleRecording_New(SaveData *saveData, enum HeapID heapID, int *resultCode);
void BattleRecording_Free(void);
BOOL BattleRecording_Exists(void);
BattleRecording *BattleRecording_Get(void);
void *BattleRecording_GetData(void);
BOOL BattleRecording_LoadSavedRecording(SaveData *saveData, int param1, int *param2, FieldBattleDTO *param3, int param4);
BOOL BattleRecording_IsSavedRecordingValid(SaveData *saveData, int param1, int *param2, int param3);
int BattleRecording_SaveStep(SaveData *saveData, BattleRecording *param1, int param2, u16 *param3);
int BattleRecording_SaveToSaveData(SaveData *saveData, int param1, int param2, int param3, u16 *param4, u16 *param5);
void sub_0202F4C0(int param0, int *param1, int *param2);
void sub_0202F858(void *param0, u32 param1, u32 param2);
void BattleRecording_WriteBattlerInputByte(int param0, int param1, u8 param2);
u8 BattleRecording_ReadBattlerInputByte(int param0, int param1);
void BattleRecording_CaptureBattleDTO(FieldBattleDTO *param0);
void BattleRecording_SetSystemVersion(int param0, u32 param1);
BOOL BattleRecording_AreSystemVersionsSupported(void);
void BattleRecording_RestoreBattleDTO(FieldBattleDTO *param0, SaveData *saveData);
UnkStruct_0202F41C *sub_0202FD88(enum HeapID heapID);
UnkStruct_02030A80 *sub_0202FDB8(enum HeapID heapID);
UnkStruct_02030A80 *sub_0202FDE8(void);
UnkStruct_0202F41C *sub_0202FE04(void);
void sub_0202FE20(UnkStruct_02030A80 *param0, UnkStruct_0202F41C *param1, UnkStruct_0202F298 *param2, FieldBattleDTO *param3, SaveData *saveData);
u64 sub_0202FE98(UnkStruct_0202F41C *param0, int param1, int param2);
UnkStruct_0202F41C *sub_0202FF2C(enum HeapID heapID);
void sub_0202FF44(UnkStruct_0202F41C *param0);

#endif // POKEPLATINUM_BATTLE_RECORDING_H
