#ifndef TILE_H
#define TILE_H

#include "object.h"

typedef enum {
    TILE_GRASS = 0,
    TILE_WATER,
} tile_type_t;

typedef struct {
    object_t obj;
} tile_t;

int tile_init(tile_t *self, tile_type_t type, int64_t x, int64_t y); 

#endif