#ifndef POKEPLATINUM_OVERLAY059_MIXED_RECORDS_LOBBY_H
#define POKEPLATINUM_OVERLAY059_MIXED_RECORDS_LOBBY_H

#include "struct_decls/struct_020961E8_decl.h"

#include "overlay_manager.h"

int Overlay059_Init(ApplicationManager *appMan, int *param1);
int Overlay059_Main(ApplicationManager *appMan, int *param1);
int Overlay059_Exit(ApplicationManager *appMan, int *param1);
void Overlay059_ShowMixedRecordsExchangeStatus(UnkStruct_020961E8 *param0);
void Overlay059_HandleCommunicationStateEvent(UnkStruct_020961E8 *param0, int param1, u8 param2);
void Overlay059_HandleParticipantJoinNotification(UnkStruct_020961E8 *param0, int param1, u8 param2);
int ov59_021D2544(void);

#endif // POKEPLATINUM_OVERLAY059_MIXED_RECORDS_LOBBY_H
