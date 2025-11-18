#include "sshmud/map_chunk.h"

static void chunk_construct(chunk_t *self, map_type_t type, uint64_t seed);
static void chunk_construct_test(chunk_t *self, uint64_t seed);

int map_generate_chunk(map_t *self, int64_t x, int64_t y) {
    chunk_t *chunk = malloc(sizeof(chunk_t));

    if (!chunk) return -1;

    chunk_init(chunk, x, y);
    chunk_construct(chunk, self->type, self->seed);

    hmput(self->chunks, chunk->pos, chunk);

    return 0;
}

chunk_t *map_get_chunk(map_t *self, int64_t x, int64_t y) {
    chunk_pos_t pos = { .x = x, .y = y };

    int64_t idx = hmgeti(self->chunks, pos);

    return idx == -1 ? NULL : self->chunks[idx].value;
}

static void chunk_construct(chunk_t *self, map_type_t type, uint64_t seed) {
    switch (type) {
        case MAP_TEST:
            chunk_construct_test(self, seed);
            break;
    }
}

static void chunk_construct_test(chunk_t *self, uint64_t seed) {
    for (size_t y = 0; y < CHUNK_SIZE; y++) {
        for (size_t x = 0; x < CHUNK_SIZE; x++) {
            int64_t noise_x = x + (CHUNK_SIZE * self->pos.x) + seed;
            int64_t noise_y = y + (CHUNK_SIZE * self->pos.y) + seed;

            float noise = stb_perlin_noise3(noise_x / 10.0f, noise_y / 10.0f, 0, 0, 0, 0);

            if (noise < -0.5) {
                tile_init(&self->tiles[y][x], TILE_WATER, x + (CHUNK_SIZE * self->pos.x), y + (CHUNK_SIZE * self->pos.y));
            } else {
                tile_init(&self->tiles[y][x], TILE_GRASS, x + (CHUNK_SIZE * self->pos.x), y + (CHUNK_SIZE * self->pos.y));
            }
        }
    }
}