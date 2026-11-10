#ifndef POKEPLATINUM_UNK_0207C63C_H
#define POKEPLATINUM_UNK_0207C63C_H

#include "struct_defs/struct_0207C894.h"
#include "struct_defs/struct_0207C8C4.h"

#include "g3d_pipeline.h"

void EvolutionScene_HideAllPlanes(void);
void EvolutionScene_ConfigureBlendAlpha(void);
G3DPipelineBuffers *EvolutionScene_Init3DPipeline(enum HeapID heapID);
void EvolutionScene_Configure3DRenderState(void);
void EvolutionParticleSystem_InitializeResources(void);
void EvolutionParticleSystem_DrawAndUpdate(void);
UnkStruct_0207C8C4 *EvolutionParticleSystem_New(UnkStruct_0207C894 *param0);
void EvolutionParticleSystem_CreateEmitter(UnkStruct_0207C8C4 *param0, int param1);
BOOL EvolutionParticleSystem_HasActiveEmitters(UnkStruct_0207C8C4 *param0);
void EvolutionParticleSystem_Free(UnkStruct_0207C8C4 *param0);

#endif // POKEPLATINUM_UNK_0207C63C_H
