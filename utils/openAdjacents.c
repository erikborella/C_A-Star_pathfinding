#include "../structs/board.c"
#include "../structs/node.c"

#ifndef OPEN_ADJACENTS_C
#define OPEN_ADJACENTS_C

bool _isPositionValid(Board *board, int x, int y) {
    return (x >= 0 && x < board->xSize && y >= 0 && y < board->ySize);
}


void openNode(Node *node, Node *nextNode, Node *finalNode) {
    if (nextNode->lastNode == NULL) {
        nextNode->lastNode = node;
        calculateDistances(nextNode, finalNode);
    } else {
        Node copyNode = *nextNode;
        copyNode.lastNode = node;

        calculateDistances(&copyNode, finalNode);

        if (copyNode.distances.totalCost < nextNode->distances.totalCost) {
            *nextNode = copyNode;
        }
    }
}

void openAdjacents(Board *board, Node *node, Node *finalNode) {
    node->isOpen = true;
    Position nodePosition = node->position;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {

            if ((i != 0 || j != 0) && 
            _isPositionValid(board, nodePosition.x+j, nodePosition.y+i)) {

                Node *nextNode = &board->board[nodePosition.y+i][nodePosition.x+j];

                if (!nextNode->isWall && !nextNode->isOpen)
                    openNode(node, nextNode, finalNode);
                
            }

        }
    }
    
}

#endif