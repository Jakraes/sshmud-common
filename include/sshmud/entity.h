#ifndef ENTITY_H
#define ENTITY_H

#include "object.h"

typedef enum {
    ENTITY_PLAYER = 0,
} entity_type_t;

typedef struct {
    object_t obj;
    entity_type_t type;
} entity_t;

int entity_init(entity_t *self, entity_type_t type, int64_t x, int64_t y);

#endif