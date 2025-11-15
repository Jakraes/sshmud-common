#ifndef CHUNK_H
#define CHUNK_H

#include "entity.h"
#include "item.h"
#include "tile.h"

#define CHUNK_SIZE 8

typedef struct {
    int64_t x, y;
} chunk_pos_t;

typedef struct {
    chunk_pos_t pos;
    tile_t tiles[CHUNK_SIZE * CHUNK_SIZE];
    entity_t entities[CHUNK_SIZE * CHUNK_SIZE];
    item_t items[CHUNK_SIZE * CHUNK_SIZE];
} chunk_t;

int chunk_init(chunk_t *self, int64_t x, int64_t y);

#endif