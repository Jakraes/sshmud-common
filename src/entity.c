#include "sshmud/entity.h"

static void entity_construct(entity_t *self, const entity_type_t type);
static void entity_construct_player(entity_t *self);

int entity_init(entity_t *self, const entity_type_t type, const int64_t x, const int64_t y) {
    if (!self) return -1;

    entity_construct(self, type);

    self->obj.x = x;
    self->obj.y = y;

    return 0;
}

static void entity_construct(entity_t *self, const entity_type_t type) {
    self->type = type;

    switch (type) {
        case ENTITY_PLAYER:
            entity_construct_player(self);
            break;
    }
}

static void entity_construct_player(entity_t *self) {
    object_init(&self->obj, "Player", '@', COLOR_BRIGHT_WHITE, COLOR_BLACK, MOD_BOLD, 0, 0);
}