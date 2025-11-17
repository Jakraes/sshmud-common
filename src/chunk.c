#include "sshmud/chunk.h"

int chunk_init(chunk_t *self, const int64_t x, const int64_t y) {
    if (!self) return -1;

    self->pos.x = x;
    self->pos.y = y;

    return 0;
}