#include "sshmud.h"
#include <stdio.h>
int main() {
    map_t *map = malloc(sizeof(map_t));

    map_init(map, 124, MAP_TEST);

    for (int y = 0; y <= 2; y++) {
        for (int x = 0; x <= 2; x++) {
            map_generate_chunk(map, x, y);
        }
    }

    for (int y = 0; y < 3 * CHUNK_SIZE; y++) {
        for (int x = 0; x < 3 * CHUNK_SIZE; x++) {
            int chunk_x = x / CHUNK_SIZE;
            int chunk_y = y / CHUNK_SIZE;

            chunk_t *chunk = map_get_chunk(map, chunk_x, chunk_y);

            printf("%c ", chunk->tiles[y - chunk_y * CHUNK_SIZE][x - chunk_x * CHUNK_SIZE].type == TILE_GRASS ? '.' : '~');
        }
        printf("\n");
    }

    map_destroy(map);

    return 0;
}