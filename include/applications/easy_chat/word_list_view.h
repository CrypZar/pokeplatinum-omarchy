#ifndef POKEPLATINUM_APPLICATIONS_EASY_CHAT_WORD_LIST_VIEW_H
#define POKEPLATINUM_APPLICATIONS_EASY_CHAT_WORD_LIST_VIEW_H

#include "applications/easy_chat/main.h"
#include "applications/easy_chat/struct_ov20_021D2128_decl.h"
#include "applications/easy_chat/easy_chat_word_list_view_decl.h"

#include "easy_chat_word_list.h"

EasyChatWordListView *EasyChatWordListView_New(UnkStruct_ov20_021D2128 *param0, const EasyChatApp *param1, const EasyChatWordList *param2);
void EasyChatWordListView_Free(EasyChatWordListView *param0);
void EasyChatWordListView_PrepareDisplay(EasyChatWordListView *param0);
void EasyChatWordListView_DrawPage(EasyChatWordListView *param0);
void EasyChatWordListView_BeginShowTransition(EasyChatWordListView *param0);
BOOL EasyChatWordListView_IsShowTransitionComplete(EasyChatWordListView *param0);
void EasyChatWordListView_BeginHideTransition(EasyChatWordListView *param0);
BOOL EasyChatWordListView_IsHideTransitionComplete(EasyChatWordListView *param0);
void EasyChatWordListView_SetSelectionIndicatorsVisible(EasyChatWordListView *param0, BOOL param1);
void EasyChatWordListView_SetCursorIndex(EasyChatWordListView *param0, u32 param1);
void EasyChatWordListView_ScrollByRows(EasyChatWordListView *param0, int param1);
BOOL EasyChatWordListView_IsScrollComplete(EasyChatWordListView *param0);

#endif // POKEPLATINUM_OV20_021D40E8_H
