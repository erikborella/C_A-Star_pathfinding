#include <stdbool.h>
#include "position.c"
#include "distances.c"

#ifndef NODE_C
#define NODE_C

struct Node {
    Position position;
    Distances distances;
    bool isWall;
    bool isOpen;
    struct Node *lastNode;
};

typedef struct Node Node;

#endif