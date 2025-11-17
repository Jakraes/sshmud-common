#ifndef MAP_CHUNK_H
#define MAP_CHUNK_H

#include "sshmud/map.h"
#include "sshmud/chunk.h"
#include "sshmud/util.h"
#include "sshmud/external/stb_perlin.h"

int map_generate_chunk(map_t *self, chunk_pos_t pos);
chunk_t *map_get_chunk(map_t *self, chunk_pos_t pos);

#endif