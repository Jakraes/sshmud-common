#ifndef MAP_H
#define MAP_H

#include "entity.h"
#include "tile.h"
#include "item.h"

typedef enum {
    MAP_WORLD = 0,
    MAP_DUNGEON,
    MAP_TEST
} map_type_t;

typedef struct {
    map_type_t type;
    uint32_t w, h;
    tile_t *tiles;
    entity_t *entities;
    item_t *items;
} map_t;

int map_init(map_t *self, map_type_t type, uint32_t w, uint32_t h);
int map_destroy(map_t *self);

#endif