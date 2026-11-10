#ifndef POKEPLATINUM_SCRCMD_BATTLE_TOWER_H
#define POKEPLATINUM_SCRCMD_BATTLE_TOWER_H

#include "field_script_context.h"

BOOL ScrCmd_InitBattleTower(ScriptContext *ctx);
BOOL ScrCmd_SetBattleTowerNull(ScriptContext *ctx);
BOOL ScrCmd_FreeBattleTower(ScriptContext *ctx);
BOOL ScrCmd_CallBattleTowerFunction(ScriptContext *ctx);
BOOL ScrCmd_GetBattleTowerPartnerSpeciesAndMove(ScriptContext *ctx);
BOOL ScrCmd_GetBattleTowerTrophyReward(ScriptContext *ctx);
BOOL ScrCmd_GetBattleTowerTrophyRewardStatus(ScriptContext *ctx);
BOOL ScrCmd_BattleTower_SendCommMessage(ScriptContext *ctx);
BOOL ScrCmd_ReceiveBattleTowerData(ScriptContext *ctx);
BOOL ScrCmd_GetBattleTowerMatchIndices(ScriptContext *ctx);
BOOL ScrCmd_BattleTower_CheckHasMatchListData(ScriptContext *ctx);
BOOL ScrCmd_ShowBattlePoints(ScriptContext *ctx);
BOOL ScrCmd_HideBattlePoints(ScriptContext *ctx);
BOOL ScrCmd_UpdateBPDisplay(ScriptContext *ctx);
BOOL ScrCmd_GetBattlePoints(ScriptContext *ctx);
BOOL ScrCmd_GiveBattlePoints(ScriptContext *ctx);
BOOL ScrCmd_RemoveBattlePoints(ScriptContext *ctx);
BOOL ScrCmd_CheckBattlePoints(ScriptContext *ctx);
BOOL ScrCmd_GetExchangeServiceCornerItemAndCost(ScriptContext *ctx);

#endif // POKEPLATINUM_SCRCMD_BATTLE_TOWER_H
