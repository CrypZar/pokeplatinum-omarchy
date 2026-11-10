#ifndef POKEPLATINUM_STRUCT_DEF_TV_H
#define POKEPLATINUM_STRUCT_DEF_TV_H

#include "constants/tv_broadcast.h"

#include "struct_defs/tv_amity_square_watch_data.h"
#include "struct_defs/tv_poffin_corner_data.h"
#include "struct_defs/tv_battle_tower_corner_outcome.h"
#include "struct_defs/tv_safari_game_data.h"
#include "struct_defs/tv_battle_frontier_frontline_news_single_data.h"
#include "struct_defs/tv_battle_frontier_frontline_news_multi_data.h"
#include "struct_defs/tv_battle_points_news_data.h"
#include "struct_defs/struct_0202E834.h"
#include "struct_defs/tv_segment_contest_hall_showcased_pokemon.h"

#include "charcode.h"

#define TV_BROADCAST_MAX_PLAYED_SEGMENTS 4

typedef struct TVSegmentInstance {
    u8 segmentID;
    u8 timesPlayed;
    u32 timestamp;
    u8 segment[40];
} TVSegmentInstance;

typedef struct TVEpisode {
    u8 segmentID;
    u8 gameVersion;
    u8 language;
    u8 gender;
    charcode_t name[8];
    TVSegmentInstance *details;
} TVEpisode;

typedef struct TVWifiEpisode {
    u32 trainerID;
    u8 gender;
    u8 gameVersion;
    u8 language;
    u16 name[8];
    TVSegmentInstance details;
} TVWifiEpisode;

typedef struct TVBroadcast {
    u8 playedSegments[TV_BROADCAST_MAX_PLAYED_SEGMENTS];
    int timeSlotMinutesRemaining;
    u8 programFinished;
    TVSegmentInstance unk_0C[4];
    TVSegmentInstance unk_C4[4];
    TVSegmentInstance unk_17C[4];
    TVWifiEpisode unk_234[16];
    TVWifiEpisode unk_684[8];
    TVWifiEpisode unk_8AC[8];
    TVSegment_ContestHall_ShowcasedPokemon showcasedPokemon;
    TVAmitySquareWatchData unk_ADE;
    TVPoffinCornerData unk_B02;
    TVBattleTowerCornerOutcome unk_B04;
    TVSafariGameData safariGame;
    TVBattleFrontierFrontlineNewsSingleData unk_B10;
    TVBattleFrontierFrontlineNewsMultiData unk_B2E;
    TVBattlePointsNewsData battlePointData;
    TVBroadcast_GTSData gtsData;
} TVBroadcast;

#endif // POKEPLATINUM_STRUCT_DEF_TV_H
