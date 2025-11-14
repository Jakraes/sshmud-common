#ifndef ITEM_H
#define ITEM_H

#include "object.h"

typedef enum {
    ITEM_IRON_SHORTSWORD = 0
} item_type_t;

typedef struct {
    object_t obj;
    item_type_t type;
} item_t;

int item_init(item_t *self, item_type_t type, int64_t x, int64_t y);

#endif