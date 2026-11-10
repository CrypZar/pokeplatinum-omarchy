#ifndef POKEPLATINUM_APPLICATIONS_EASY_CHAT_SENTENCE_VIEW_H
#define POKEPLATINUM_APPLICATIONS_EASY_CHAT_SENTENCE_VIEW_H

#include "applications/easy_chat/main.h"
#include "applications/easy_chat/struct_ov20_021D2128_decl.h"
#include "applications/easy_chat/easy_chat_sentence_view_decl.h"

#include "easy_chat_word_list.h"
#include "narc.h"

EasyChatSentenceView *EasyChatSentenceView_New(UnkStruct_ov20_021D2128 *param0, const EasyChatApp *param1, const EasyChatWordList *param2);
void EasyChatSentenceView_Free(EasyChatSentenceView *param0);
void EasyChatSentenceView_Initialize(EasyChatSentenceView *param0, NARC *param1);
void EasyChatSentenceView_DrawSentence(EasyChatSentenceView *param0);
u32 EasyChatSentenceView_GetSlotCount(const EasyChatSentenceView *param0);
void EasyChatSentenceView_DrawInstruction(EasyChatSentenceView *param0, u32 param1);
void EasyChatSentenceView_SetCursorInactive(EasyChatSentenceView *param0);
void EasyChatSentenceView_SetCursorActive(EasyChatSentenceView *param0);
void EasyChatSentenceView_SetCursorVisible(EasyChatSentenceView *param0, BOOL param1);
void EasyChatSentenceView_HideNavigationArrows(EasyChatSentenceView *param0);
void EasyChatSentenceView_ShowNavigationArrows(EasyChatSentenceView *param0);
void EasyChatSentenceView_SetCursorPositionForSlot(EasyChatSentenceView *param0, int param1);
void EasyChatSentenceView_DrawActionPrompt(EasyChatSentenceView *param0, int param1);
void EasyChatSentenceView_UpdateActionPromptSelection(EasyChatSentenceView *param0, int param1);
void EasyChatSentenceView_ClearActionPrompt(EasyChatSentenceView *param0);

#endif // POKEPLATINUM_OV20_021D2EA4_H
