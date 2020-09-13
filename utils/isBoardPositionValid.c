#include <stdio.h>

#include "../structs/board.c"

#ifndef IS_BOARD_POSITION_VALID_C
#define IS_BOARD_POSITION_VALID_C

bool isBoardPositionValid(Board *board, int x, int y) {
    return (x >= 0 && x < board->xSize && y >= 0 && y < board->ySize);
}


#endif