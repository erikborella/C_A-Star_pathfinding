#include "../structs/board.c"

#ifndef BOARD_CREATOR_C
#define BOARD_CREATOR_C

void initNode(Node *node) {
    node->isWall = false;
    node->isOpen = false;

    node->lastNode = NULL;

    node->distances.gCost = 0;
    node->distances.hCost = 0;
    node->distances.totalCost = 0;
}

Board createBoard(int xSize, int ySize) {
    Board board;
    board.xSize = xSize;
    board.ySize = ySize;

    board.board = malloc(sizeof(Node*) * ySize);

    for (int i = 0; i < ySize; i++) {
        board.board[i] = malloc(sizeof(Node) * xSize);

        for (int j = 0; j < xSize; j++) {
            Node node;

            initNode(&node);

            node.position.y = i;
            node.position.x = j;

            board.board[i][j] = node;
        }

    }

    return board;
};

void freeBoard(Board board) {
    for (int i = 0; i < board.ySize; i++) {
        free(board.board[i]);
    }

    free(board.board);
};

#endif