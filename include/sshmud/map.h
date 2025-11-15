#ifndef MAP_H
#define MAP_H

#include "chunk.h"
#include "external/stb_ds.h"

typedef enum {
    MAP_WORLD = 0,
    MAP_DUNGEON,
    MAP_TEST
} map_type_t;

typedef struct {
    map_type_t type;
    uint64_t seed;
    struct { chunk_pos_t key; chunk_t *value; } *chunks;   
} map_t;

int map_init(map_t *self, map_type_t type);
int map_destroy(map_t *self);
chunk_t *map_get_chunk(map_t *self, chunk_pos_t pos);
int map_generate_chunk(map_t *self, chunk_pos_t pos);

#endif