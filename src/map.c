#include "sshmud/map.h"

int map_init(map_t *self, uint64_t seed, map_type_t type) {
    if (!self) return -1;
 
    self->type = type; 
    self->seed = seed;
    self->chunks = NULL;
    self->player_count = 0;
 
    return 0;
}

int map_destroy(map_t *self) {
    if (!self) return -1;
 
    for (int64_t i = 0; i < hmlen(self->chunks); i++) {
        free(self->chunks[i].value);
    }

    hmfree(self->chunks);
    
    return 0;
}

int map_add_player(map_t *self, entity_t *player) {
    if (!self || !player) return -1;
 
    if (self->player_count >= MAP_PLAYER_MAX) return -1;
 
    self->players[self->player_count++] = *player;
 
    return 0;
}

int map_remove_player(map_t *self, entity_t *player) {
    if (!self || !player) return -1;
 
    for (size_t i = 0; i < self->player_count; i++) {
        if (&self->players[i] == player) {
            self->players[i] = self->players[--self->player_count];
 
            break;
        }
    }
 
    return 0;
}