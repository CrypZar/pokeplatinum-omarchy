#ifndef POKEPLATINUM_APPLICATIONS_EASY_CHAT_CATEGORIES_H
#define POKEPLATINUM_APPLICATIONS_EASY_CHAT_CATEGORIES_H

#include "applications/easy_chat/main.h"
#include "applications/easy_chat/struct_ov20_021D2128_decl.h"
#include "applications/easy_chat/struct_ov20_021D4E8C.h"
#include "applications/easy_chat/struct_ov20_021D4FF0.h"

#include "easy_chat_word_list.h"
#include "narc.h"
#include "sprite.h"

typedef struct {
    UnkStruct_ov20_021D2128 *unk_00;
    const EasyChatApp *easyChatApp;
    const EasyChatWordList *unk_08;
    BgConfig *bgConfig;
    u32 unk_10;
    u32 unk_14;
    int dummy;
    UnkStruct_ov20_021D4FF0 unk_1C;
    UnkStruct_ov20_021D4E8C unk_3C;
    Sprite *cursorSprite;
} EasyChatCategoriesContext;

EasyChatCategoriesContext *EasyChatCategoriesContext_New(UnkStruct_ov20_021D2128 *param0, const EasyChatApp *easyChatApp, const EasyChatWordList *param2);
void EasyChatCategoriesContext_Free(EasyChatCategoriesContext *ctx);
void EasyChatCategories_DrawInterface(EasyChatCategoriesContext *ctx, NARC *narc);
void EasyChatCategories_SetCursorVisible(EasyChatCategoriesContext *ctx, BOOL param1);
void EasyChatCategories_DrawCursor(EasyChatCategoriesContext *ctx, u32 selectedIndex);
void EasyChatCategories_BeginShowAnimation(EasyChatCategoriesContext *ctx);
BOOL EasyChatCategories_IsShowAnimationComplete(EasyChatCategoriesContext *ctx);
void EasyChatCategories_BeginHideAnimation(EasyChatCategoriesContext *ctx);
BOOL EasyChatCategories_IsHideAnimationComplete(EasyChatCategoriesContext *ctx);
void EasyChatCategories_ResetVerticalOffset(EasyChatCategoriesContext *ctx);
void EasyChatCategories_BeginFadeToBlack(EasyChatCategoriesContext *ctx);
BOOL EasyChatCategories_IsFadeToBlackComplete(EasyChatCategoriesContext *ctx);
void EasyChatCategories_BeginAlphaFadeOut(EasyChatCategoriesContext *ctx);
BOOL EasyChatCategories_FinishAlphaFadeOutAndHideLayer(EasyChatCategoriesContext *ctx);
void EasyChatCategories_BeginAlphaFadeIn(EasyChatCategoriesContext *ctx);
BOOL EasyChatCategories_IsAlphaFadeInComplete(EasyChatCategoriesContext *ctx);
void EasyChatCategories_SetModeOffset(EasyChatCategoriesContext *ctx);
void EasyChatCategories_BeginModeSlide(EasyChatCategoriesContext *ctx);
BOOL EasyChatCategories_IsModeSlideComplete(EasyChatCategoriesContext *ctx);

#endif // POKEPLATINUM_APPLICATIONS_EASY_CHAT_CATEGORIES_H
