#ifndef POKEPLATINUM_APPLICATIONS_EASY_CHAT_MODE_SELECTOR_H
#define POKEPLATINUM_APPLICATIONS_EASY_CHAT_MODE_SELECTOR_H

#include "applications/easy_chat/main.h"
#include "applications/easy_chat/struct_ov20_021D2128_decl.h"
#include "applications/easy_chat/easy_chat_mode_selector_decl.h"

#include "easy_chat_word_list.h"
#include "narc.h"

EasyChatModeSelector *EasyChatModeSelector_New(UnkStruct_ov20_021D2128 *param0, const EasyChatApp *param1, const EasyChatWordList *param2);
void EasyChatModeSelector_Free(EasyChatModeSelector *param0);
void EasyChatModeSelector_Initialize(EasyChatModeSelector *param0, NARC *param1);
void EasyChatModeSelector_SetCursorSelectedAnimation(EasyChatModeSelector *param0);
void EasyChatModeSelector_SetCursorDefaultAnimation(EasyChatModeSelector *param0);
void EasyChatModeSelector_SetCursorVisible(EasyChatModeSelector *param0, BOOL param1);
BOOL EasyChatModeSelector_IsCursorVisible(EasyChatModeSelector *param0);
void EasyChatModeSelector_SetSelectedMode(EasyChatModeSelector *param0, int param1);
void EasyChatModeSelector_ShowCategoryModeLabels(EasyChatModeSelector *param0);
void EasyChatModeSelector_RestoreDefaultBackgroundOffset(EasyChatModeSelector *param0);

#endif // POKEPLATINUM_OV20_021D3864_H
