#ifndef POKEPLATINUM_OVERLAY059_STATUS_PALETTE_ANIMATION_H
#define POKEPLATINUM_OVERLAY059_STATUS_PALETTE_ANIMATION_H

#include <nnsys.h>

typedef struct {
    int isActive;
    int currentStepIndex;
    int framesInCurrentStep;
    void *paletteDataBuffer;
    NNSG2dPaletteData *paletteData;
} Overlay059StatusPaletteAnimationState;

#endif // POKEPLATINUM_OVERLAY059_STATUS_PALETTE_ANIMATION_H
