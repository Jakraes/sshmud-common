#ifndef MESSAGE_H
#define MESSAGE_H

#include <stdint.h>

#include "chunk.h"

typedef enum {
    MSG_PING = 0,
    MSG_CONNECT,
    MSG_MOVE,
    MSG_CHUNK
} message_type_t;

typedef enum {
    MSG_REQUEST = 0,
    MSG_APPROVED,
    MSG_DENIED
} message_status_t;

typedef struct {
    message_type_t type;
    message_status_t status;
    union {
        struct { uint64_t id; } connect;
        struct { uint32_t x, y, dir; } move; // 0 = up, 1 = down, 2 = left, 3 = right
        chunk_t chunk;
    } data;
} message_t;

#endif