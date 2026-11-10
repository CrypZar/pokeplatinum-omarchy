#ifndef POKEPLATINUM_EVOLUTION_PARTICLE_SYSTEM_H
#define POKEPLATINUM_EVOLUTION_PARTICLE_SYSTEM_H

#include "struct_defs/evolution_particle_system_config.h"

#include "particle_system.h"
#include "spl.h"

typedef struct {
    EvolutionParticleSystemConfig unk_00;
    SPLEmitter *unk_08;
    ParticleSystem *unk_0C;
} EvolutionParticleSystem;

#endif // POKEPLATINUM_STRUCT_0207C8C4_H
