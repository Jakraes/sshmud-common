#ifndef MAP_H
#define MAP_H

#include "external/stb_ds.h"
#include "chunk.h"

#define MAP_PLAYER_MAX 8

typedef enum {
    MAP_TEST = 0,
} map_type_t;

typedef struct {
    map_type_t type;
    uint64_t seed;
    struct { chunk_pos_t key; chunk_t *value; } *chunks;
    entity_t players[MAP_PLAYER_MAX];
    size_t player_count;
} map_t;

int map_init(map_t *self, uint64_t seed, map_type_t type);
int map_destroy(map_t *self);
int map_add_player(map_t *self, entity_t *player);
int map_remove_player(map_t *self, entity_t *player);

#endif