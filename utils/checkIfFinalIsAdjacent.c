#include "../structs/node.c"
#include "../structs/board.c"

#ifndef CHECk_IF_FINAL_IS_ADJACENT_C
#define CHECk_IF_FINAL_IS_ADJACENT_C

bool checkIfFinalIsAdjacent(Board *board, Node *node, Node *finalNode) {
    Position nodePosition = node->position;

    for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {

                if ((i != 0 || j != 0) && 
                    isBoardPositionValid(board, nodePosition.x+j, nodePosition.y+i)) {
                    
                    Node *nextNode = &board->board[nodePosition.y+i][nodePosition.x+j];

                    if (nextNode == finalNode) {
                        finalNode->lastNode = node;
                        return true;
                    }

                }

            }
        }

        return false;
    }

#endif