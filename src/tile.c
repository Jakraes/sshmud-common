#include "sshmud/tile.h"

static void tile_construct(tile_t *self, tile_type_t type);
static void tile_construct_grass(tile_t *self);
static void tile_construct_water(tile_t *self);

int tile_init(tile_t *self, tile_type_t type, int64_t x, int64_t y) {
    if (!self) return -1;

    tile_construct(self, type);

    self->obj.x = x;
    self->obj.y = y;
    self->type = type;

    return 0;
}

static void tile_construct(tile_t *self, tile_type_t type) {
    switch (type) {
        case TILE_GRASS:
            tile_construct_grass(self);
            break;
        case TILE_WATER:
            tile_construct_water(self);
            break;
    }
}

static void tile_construct_grass(tile_t *self) {
    object_init(&self->obj, "Grass", '.', COLOR_GREEN, COLOR_BLACK, MOD_NORMAL, 0, 0);
}

static void tile_construct_water(tile_t *self) {
    object_init(&self->obj, "Water", '~', COLOR_CYAN, COLOR_BLACK, MOD_NORMAL, 0, 0);
}