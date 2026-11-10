#ifndef POKEPLATINUM_EASY_CHAT_TRANSITION_ANIMATIONS_H
#define POKEPLATINUM_EASY_CHAT_TRANSITION_ANIMATIONS_H

#include "applications/easy_chat/bg_scroll_animation.h"
#include "applications/easy_chat/blend_animation.h"

#include "bg_window.h"

void EasyChatBgScrollAnimation_Start(EasyChatBgScrollAnimation *param0, BgConfig *param1, u32 param2, int param3, int param4, int param5);
BOOL EasyChatBgScrollAnimation_IsComplete(EasyChatBgScrollAnimation *param0);
void EasyChatBlendAnimation_StartAlpha(EasyChatBlendAnimation *param0, int param1, int param2, int param3, int param4, int param5);
BOOL EasyChatBlendAnimation_IsAlphaComplete(EasyChatBlendAnimation *param0);
void EasyChatBlendAnimation_StartBrightness(EasyChatBlendAnimation *param0, int param1, int param2, int param3, int param4);
BOOL EasyChatBlendAnimation_IsBrightnessComplete(EasyChatBlendAnimation *param0);

#endif // POKEPLATINUM_EASY_CHAT_TRANSITION_ANIMATIONS_H
