#include "sshmud/chunk.h"

int chunk_init(chunk_t *self, int64_t x, int64_t y) {
    if (!self) return -1;

    self->pos.x = x;
    self->pos.y = y;

    self->entity_count = 0;
    self->item_count = 0;

    return 0;
}

int chunk_add_entity(chunk_t *self, entity_t *entity) {
    if (!self || !entity) return -1;

    if (self->entity_count >= CHUNK_SIZE * CHUNK_SIZE) return -1;

    self->entities[self->entity_count++] = *entity;

    return 0;
}

int chunk_add_item(chunk_t *self, item_t *item) {
    if (!self || !item) return -1;

    if (self->item_count >= CHUNK_SIZE * CHUNK_SIZE) return -1;

    self->items[self->item_count++] = *item;

    return 0;
}

int chunk_remove_entity(chunk_t *self, entity_t *entity) {
    if (!self || !entity) return -1;

    for (size_t i = 0; i < self->entity_count; i++) {
        if (&self->entities[i] == entity) {
            self->entities[i] = self->entities[--self->entity_count];

            break;
        }
    }

    return 0;
}

int chunk_remove_item(chunk_t *self, item_t *item) {
    if (!self || !item) return -1;

    for (size_t i = 0; i < self->item_count; i++) {
        if (&self->items[i] == item) {
            self->items[i] = self->items[--self->item_count];

            break;
        }
    }

    return 0;
}
