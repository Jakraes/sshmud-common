#include "sshmud/object.h"

#include <string.h>

static uint64_t id_counter = 0;

int object_init(object_t *self, const char *name, char symbol, color_t fg, color_t bg, modifier_t mod, int64_t x, int64_t y) {
    if (!self) return -1;

    self->id = id_counter++;
    strncpy(self->name, name, sizeof(self->name) - 1);
    self->name[sizeof(self->name) - 1] = '\0';

    self->glyph.symbol = symbol;
    self->glyph.fg_color = fg;
    self->glyph.bg_color = bg;
    self->glyph.modifier = mod;
    self->x = x;
    self->y = y;

    return 0;
}