#include "sshmud/chunk.h"

int chunk_init(chunk_t *self, int64_t x, int64_t y) {
    if (!self) return -1;

    self->pos.x = x;
    self->pos.y = y;

    return 0;
}