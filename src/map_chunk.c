#include "sshmud/map_chunk.h"


static void chunk_generate(chunk_t *self, map_type_t type, chunk_pos_t pos, uint64_t seed);
static void chunk_generate_world(chunk_t *self, chunk_pos_t pos, uint64_t seed);
static void chunk_generate_dungeon(chunk_t *self, chunk_pos_t pos, uint64_t seed);
static void chunk_generate_test(chunk_t *self, chunk_pos_t pos, uint64_t seed);

int map_generate_chunk(map_t *self, chunk_pos_t pos) {
    if (!self) return -1;
    
    chunk_t *chunk = malloc(sizeof(chunk_t));

    if (!chunk) return -1;

    chunk_generate(chunk, self->type, pos, self->seed);

    hmput(self->chunks, pos, chunk);

    return 0;
}

chunk_t *map_get_chunk(map_t *self, chunk_pos_t pos) {
    if (!self) return NULL;

    int64_t idx = hmgeti(self->chunks, pos);
    
    if (idx == -1) return NULL;

    return self->chunks[idx].value;
}

static void chunk_generate(chunk_t *self, map_type_t type, chunk_pos_t pos, uint64_t seed) {
    switch (type) {
        case MAP_WORLD:
            chunk_generate_world(self, pos, seed);
            break;
        case MAP_DUNGEON:
            chunk_generate_dungeon(self, pos, seed);
            break;
        case MAP_TEST:
            chunk_generate_test(self, pos, seed);
            break;
    }
}

static void chunk_generate_world(chunk_t *self, chunk_pos_t pos, uint64_t seed) {
    UNUSED(self);
    UNUSED(pos);
    UNUSED(seed);
}

static void chunk_generate_dungeon(chunk_t *self, chunk_pos_t pos, uint64_t seed) {
    UNUSED(self);
    UNUSED(pos);
    UNUSED(seed);
}

static void chunk_generate_test(chunk_t *self, chunk_pos_t pos, uint64_t seed) {
    for (int64_t x = 0; x < CHUNK_SIZE; x++) {
        for (int64_t y = 0; y < CHUNK_SIZE; y++) {
            float noise = stb_perlin_noise3((pos.x * CHUNK_SIZE + x + seed) / 10.0f, (pos.y * CHUNK_SIZE + y + seed) / 10.0f, 0, 0, 0, 0);

            if (noise < -0.2f) {
                tile_init(&self->tiles[y * CHUNK_SIZE + x], TILE_WATER, pos.x * CHUNK_SIZE + x, pos.y * CHUNK_SIZE + y);
            } else {
                tile_init(&self->tiles[y * CHUNK_SIZE + x], TILE_GRASS, pos.x * CHUNK_SIZE + x, pos.y * CHUNK_SIZE + y);
            }
        }
    }
}