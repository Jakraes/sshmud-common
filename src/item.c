#include "sshmud/item.h"

static void item_construct(item_t *self, item_type_t type);
static void item_construct_iron_shortsword(item_t *self);

int item_init(item_t *self, item_type_t type, int64_t x, int64_t y) {
    if (!self) return -1;

    item_construct(self, type);

    self->obj.x = x;
    self->obj.y = y;

    return 0;
}

static void item_construct(item_t *self, item_type_t type) {
    switch (type) {
        case ITEM_IRON_SHORTSWORD:
            item_construct_iron_shortsword(self);
            break;
    }
}

static void item_construct_iron_shortsword(item_t *self) {
    object_init(&self->obj, "Iron Shortsword", '/', COLOR_WHITE, COLOR_BLACK, MOD_NORMAL, 0, 0);
}