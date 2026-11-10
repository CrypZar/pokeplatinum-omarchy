#ifndef POKEPLATINUM_FIELD_EVENT_LOOKUP_H
#define POKEPLATINUM_FIELD_EVENT_LOOKUP_H

#include "struct_decls/map_object.h"

#include "field/field_system_decl.h"

#include "map_header_data.h"

void FieldSystem_GetMapObjectAtFacingPosition(FieldSystem *fieldSystem, MapObject **param1);
u8 sub_0203CA40(FieldSystem *fieldSystem, MapObject **param1);
u16 FieldEvent_GetInteractedBgEventScript(FieldSystem *fieldSystem, const BgEvent *bgEvents, int numBgEvents);
u16 FieldEvent_GetInteractedWallSignScript(FieldSystem *fieldSystem, const BgEvent *bgEvents, int numBgEvents);
u8 sub_0203CBE0(FieldSystem *fieldSystem, MapObject **param1);
u16 sub_0203CC14(FieldSystem *fieldSystem, void *param1, int param2);

#endif // POKEPLATINUM_FIELD_EVENT_LOOKUP_H
