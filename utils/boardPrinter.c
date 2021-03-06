#include "../structs/board.c"

#ifndef BOARD_PRINTER_C
#define BOARD_PRINTER_C

int _countDigits(int num) {
    if (num == 0)
        return 1;

    int counter = 0;

    while (num != 0) {
        num = num/10;
        counter++;
    }
    return counter;
}

int _findTotalCostBiggestNumber(Board *board) {
    int biggest = board->board[0][0].distances.totalCost;

    for (int i = 0; i < board->ySize; i++) {
        for (int j = 0; j < board->xSize; j++) {
            int num = board->board[i][j].distances.totalCost;
            if (num > biggest) {
                biggest = num;
            }
        }
    }

    return biggest;
}

void _printAligmentSpaces(int num1, int num2) {
    int diference = abs(_countDigits(num2) - _countDigits(num1));

    for (int i = 0; i < diference; i++) {
        printf("%c", ' ');
    }
}

int _findGCostBiggestNumber(Board *board) {
    int biggest = board->board[0][0].distances.gCost;

    for (int i = 0; i < board->ySize; i++) {
        for (int j = 0; j < board->xSize; j++) {
            int num = board->board[i][j].distances.gCost;
            if (num > biggest) {
                biggest = num;
            }
        }
    }

    return biggest;
}

int _findHCostBiggestNumber(Board *board) {
    int biggest = board->board[0][0].distances.hCost;

    for (int i = 0; i < board->ySize; i++) {
        for (int j = 0; j < board->xSize; j++) {
            int num = board->board[i][j].distances.hCost;
            if (num > biggest) {
                biggest = num;
            }
        }
    }

    return biggest;
}

bool _checkIfNodeIsInPath(Node *node, Node **path, int pathSize) {
    for (int i = 0; i < pathSize; i++) {
        if (path[i] == node)
            return true;
    }
    return false;
}

void printTotalsCostsBoard(Board *board) {
    int biggestTotalCostNumber = _findTotalCostBiggestNumber(board);

    for (int i = 0; i < board->ySize; i++) {
        for (int j = 0; j < board->xSize; j++) {
            int actualTotalCost = board->board[i][j].distances.totalCost;

            printf(" %d", actualTotalCost);
            _printAligmentSpaces(actualTotalCost, biggestTotalCostNumber);

            if (j != board->xSize-1)
                printf(" |");

        }
        printf("\n");
    }
}

void printGsCostsBoard(Board *board) {
    int biggestGCostNumber = _findGCostBiggestNumber(board);

    for (int i = 0; i < board->ySize; i++) {
        for (int j = 0; j < board->xSize; j++) {
            int actualGCost = board->board[i][j].distances.gCost; 

            printf(" %d", actualGCost);
            _printAligmentSpaces(actualGCost, biggestGCostNumber);
            
            if (j != board->xSize-1)
                printf(" |");

        }
        printf("\n");
    }
}

void printHsCostsBoard(Board *board) {
    int biggestHCostNumber = _findHCostBiggestNumber(board);

    for (int i = 0; i < board->ySize; i++) {
        for (int j = 0; j < board->xSize; j++) {
            int actualHCost = board->board[i][j].distances.hCost;

            printf(" %d", actualHCost);
            _printAligmentSpaces(actualHCost, biggestHCostNumber);

            if (j != board->xSize-1)
                printf(" |");
                
        }
        printf("\n");
    }
}

void printWallBoard(Board *board) {
    for (int i = 0; i < board->ySize; i++) {
        for (int j = 0; j < board->xSize; j++) {
            printf(" %c", (board->board[i][j].isWall) ? 'W':'-');
            if (j != board->xSize-1)
                printf(" |");
        }
        printf("\n");
    }
}

void printAllBoardsData(Board *board) {
    printf("\nWalls---------------\n");
    printWallBoard(board);

    printf("\nG cost---------------\n");
    printGsCostsBoard(board);

    printf("\nH cost---------------\n");
    printHsCostsBoard(board);

    printf("\nTotal Cost---------------\n");
    printTotalsCostsBoard(board);
}

void printPath(Board *board, Node **path, int pathSize) {
    for (int i = 0; i < board->ySize; i++) {
        for (int j = 0; j < board->xSize; j++) {
            printf(" %c", (_checkIfNodeIsInPath(&board->board[i][j], path, pathSize)) ? 'C':'-');
            if (j != board->xSize-1)
                printf(" |");
        }
        printf("\n");
    }
}

void printNodeInformation(Node *node) {
    printf("Position: %d:%d\n", node->position.x, node->position.y);
    printf("Costs\n");
    printf("\tGCost: %d\n\tHCost: %d\n\tTotal: %d\n", node->distances.gCost, node->distances.hCost, node->distances.totalCost);
    printf("isWall: %d\n", node->isWall);
    printf("isOpen: %d\n", node->isOpen);
    printf("LastNode: %p\n\n", node->lastNode);
}

#endif