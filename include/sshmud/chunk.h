#ifndef CHUNK_H
#define CHUNK_H

#define CHUNK_SIZE 8

#include <stddef.h>

#include "entity.h"
#include "item.h"
#include "tile.h"

typedef struct {
    int64_t x, y;
} chunk_pos_t;

typedef struct {
    chunk_pos_t pos;
    tile_t tiles[CHUNK_SIZE][CHUNK_SIZE];
    entity_t entities[CHUNK_SIZE * CHUNK_SIZE];
    item_t items[CHUNK_SIZE * CHUNK_SIZE];
    size_t entity_count, item_count;
} chunk_t;

int chunk_init(chunk_t *self, int64_t x, int64_t y);
int chunk_add_entity(chunk_t *self, entity_t *entity);
int chunk_add_item(chunk_t *self, item_t *item);
int chunk_remove_entity(chunk_t *self, entity_t *entity);
int chunk_remove_item(chunk_t *self, item_t *item);

#endif