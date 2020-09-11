#include "node.c"

#ifndef BOARD_C
#define BOARD_C

struct Board {
    Node **board;
    int xSize;
    int ySize;
};

typedef struct Board Board;

#endif