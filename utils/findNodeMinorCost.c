#include <stdio.h>

#include "../structs/node.c"
#include "../structs/board.c"

#include "boardPrinter.c"


#ifndef FIND_NODE_MINOR_COST_C
#define FIND_NODE_MINOR_COST_C

Node* findNodeMinorCost(Board *board) {
    int i, j;
    Node *minorCostNode = NULL;

    for (i = 0; i < board->ySize; i++) {
        for (j = 0; j < board->xSize; j++) {
            Node *node = &board->board[i][j];

            if (!node->isWall && 
            !node->isOpen && 
            node->lastNode != NULL) {

                if (minorCostNode == NULL) {
                    minorCostNode = node;
                } else {
                    if (node->distances.totalCost < minorCostNode->distances.totalCost) {
                        minorCostNode = node;
                    }
                }

            }
        }
    }
 
    return minorCostNode;
}

#endif