#ifndef OBJECT_H
#define OBJECT_H

#include <stdint.h>

#include "colors.h"

typedef struct {
    uint64_t id;
    char name[50];
    struct {
        char symbol;
        color_t fg_color, bg_color;
        modifier_t modifier;
    } glyph;
    int64_t x, y;
} object_t;

int object_init(object_t *self, const char *name, char symbol, color_t fg, color_t bg, modifier_t mod, int64_t x, int64_t y);

#endif