#ifndef POKEPLATINUM_EVOLUTION_GRAPHICS_H
#define POKEPLATINUM_EVOLUTION_GRAPHICS_H

#include "struct_defs/evolution_particle_system_config.h"
#include "struct_defs/evolution_particle_system.h"

#include "g3d_pipeline.h"

void EvolutionScene_HideAllPlanes(void);
void EvolutionScene_ConfigureBlendAlpha(void);
G3DPipelineBuffers *EvolutionScene_Init3DPipeline(enum HeapID heapID);
void EvolutionScene_Configure3DRenderState(void);
void EvolutionParticleSystem_InitializeResources(void);
void EvolutionParticleSystem_DrawAndUpdate(void);
EvolutionParticleSystem *EvolutionParticleSystem_New(EvolutionParticleSystemConfig *param0);
void EvolutionParticleSystem_CreateEmitter(EvolutionParticleSystem *param0, int param1);
BOOL EvolutionParticleSystem_HasActiveEmitters(EvolutionParticleSystem *param0);
void EvolutionParticleSystem_Free(EvolutionParticleSystem *param0);

#endif // POKEPLATINUM_EVOLUTION_GRAPHICS_H
