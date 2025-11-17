#include "sshmud/map.h"

#include <stdlib.h>

int map_init(map_t *self, map_type_t type) {
    if (!self) return -1;

    self->type = type;
    self->chunks = NULL;

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