#include "sshmud/map.h"

#include <stdlib.h>

static void map_construct(map_t *self);
static void map_construct_world(map_t *self);
static void map_construct_dungeon(map_t *self);
static void map_construct_test(map_t *self);

int map_init(map_t *self, map_type_t type, uint32_t w, uint32_t h) {
    if (!self) return -1;

    self->type = type;
    self->w = w;
    self->h = h;

    self->tiles = calloc(w * h, sizeof(tile_t));
    if (!self->tiles) return -1;

    self->entities = calloc(w * h, sizeof(entity_t));
    if (!self->entities) return -1;

    self->items = calloc(w * h, sizeof(item_t));
    if (!self->items) return -1;

    return 0;
}

int map_destroy(map_t *self) {
    if (!self) return -1;

    free(self->tiles);
    free(self->entities);
    free(self->items);

    return 0;
}

static void map_construct(map_t *self) {
    switch (self->type) {
        case MAP_WORLD:
            map_construct_world(self);
            break;
        case MAP_DUNGEON:
            map_construct_dungeon(self);
            break;
        case MAP_TEST:
            map_construct_test(self);
            break;
        default:
            /* Handle unknown map types if necessary */
            break;
    }
}

static void map_construct_world(map_t *self) {

}

static void map_construct_dungeon(map_t *self) {

}

static void map_construct_test(map_t *self) {
    for (uint32_t y = 0; y < self->h; y++) {
        for (uint32_t x = 0; x < self->w; x++) {
            tile_t tile;

            tile_init(&tile, TILE_GRASS, x, y);

            self->tiles[y * self->w + x] = tile;
        }
    }
}