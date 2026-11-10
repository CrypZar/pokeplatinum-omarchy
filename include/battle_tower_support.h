#ifndef POKEPLATINUM_BATTLE_TOWER_SUPPORT_H
#define POKEPLATINUM_BATTLE_TOWER_SUPPORT_H

#include "field/field_system_decl.h"

#include "field_task.h"
#include "savedata.h"

void BattleTower_SelectPokemon(FieldTask *param0, void **param1, u8 param2, u8 param3, u8 param4, u8 param5, u8 param6, u8 param7);
void WifiBattleTowerTask_Start(FieldTask *param0, u16 param1, u16 param2, u16 param3);
void BattleTower_StartReceivedDataTask(FieldTask *param0, u16 param1, u16 param2);
u16 BattleTower_ClaimPendingTrophyReward(SaveData *saveData);
u16 BattleTower_GetPendingTrophyRewardStatus(SaveData *saveData);
u32 BattleTower_RngNext(u32 param0);
u32 BattleTower_RngNext2(u32 param0);
u32 WifiBattleTower_SeedRandomStateFromMixedRecords(SaveData *saveData);
u32 WifiBattleTower_GenerateNextMatchSeed(SaveData *saveData);
u32 WifiBattleTower_GenerateRoomSeed(SaveData *saveData);
BOOL FieldSystem_IsInBattleTowerSalon(FieldSystem *fieldSystem);

#endif // POKEPLATINUM_BATTLE_TOWER_SUPPORT_H
