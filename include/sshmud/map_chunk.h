#ifndef MAP_CHUNK_H
#define MAP_CHUNK_H

#include <stdlib.h>

#include "map.h"
#include "external/stb_perlin.h"

int map_generate_chunk(map_t *self, int64_t x, int64_t y);
chunk_t *map_get_chunk(map_t *self, int64_t x, int64_t y);

#endif