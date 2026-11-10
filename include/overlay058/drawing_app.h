#ifndef POKEPLATINUM_OVERLAY058_DRAWING_APP_H
#define POKEPLATINUM_OVERLAY058_DRAWING_APP_H

#include "struct_decls/struct_02095EAC_decl.h"

#include "overlay_manager.h"

int Overlay058_Init(ApplicationManager *appMan, int *param1);
int Overlay058_Main(ApplicationManager *appMan, int *param1);
int Overlay058_Exit(ApplicationManager *appMan, int *param1);
void Overlay058_HandleCommunicationStateEvent(UnkStruct_02095EAC *param0, int param1, u8 param2);
int Overlay058_CountParticipantsWithTrainerInfo(void);

#endif // POKEPLATINUM_OVERLAY058_DRAWING_APP_H
