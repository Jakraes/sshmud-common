#include "sshmud/map.h"

#include <stdlib.h>

static void map_construct(map_t *self, map_type_t type);
static void map_generate_world_chunk(map_t *self, chunk_pos_t pos);
static void map_generate_dungeon_chunk(map_t *self, chunk_pos_t pos);
static void map_generate_test_chunk(map_t *self, chunk_pos_t pos);

int map_init(map_t *self, map_type_t type) {
    if (!self) return -1;

    self->type = type;
    self->chunks = NULL;

    map_construct(self, type);

    return 0;
}

int map_destroy(map_t *self) {
    if (!self) return -1;

    for (int i = 0; i < hmlen(self->chunks); i++) {
        free(self->chunks[i].value);
    }

    hmfree(self->chunks);

    return 0;
}

chunk_t *map_get_chunk(map_t *self, chunk_pos_t pos) {
    chunk_t *chunk = NULL;
    int64_t idx = hmgeti(self->chunks, pos);

    if (idx >= 0) {
        chunk = self->chunks[idx].value;
    }
    
    return chunk;
}

int map_generate_chunk(map_t *self, chunk_pos_t pos) {
    chunk_t *chunk = malloc(sizeof(chunk_t));

    if (!chunk) return -1;

    chunk_init(chunk, pos.x, pos.y);

    switch (self->type) {
        case MAP_WORLD:
            map_generate_world_chunk(self, pos);
            break;
        case MAP_DUNGEON:
            map_generate_dungeon_chunk(self, pos);
            break;
        case MAP_TEST:
            map_generate_test_chunk(self, pos);
            break;
    }

    hmput(self->chunks, pos, chunk);

    return 0;
}

static void map_construct(map_t *self, map_type_t type) {
    self = self;
    type = type;
    // TODO
}

static void map_generate_world_chunk(map_t *self, chunk_pos_t pos) {
    self = self;
    pos = pos;
    // TODO
}

static void map_generate_dungeon_chunk(map_t *self, chunk_pos_t pos) {
    self = self;
    pos = pos;
    // TODO
}

static void map_generate_test_chunk(map_t *self, chunk_pos_t pos) {
    self = self;
    pos = pos;
    // TODO
}
