#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "structs/position.c"
#include "structs/distances.c"
#include "structs/node.c"
#include "structs/board.c"

#include "utils/boardCreator.c"
#include "utils/distanceCalculator.c"
#include "utils/openAdjacents.c"
#include "utils/boardPrinter.c"
#include "utils/findNodeMinorCost.c"
#include "utils/checkIfFinalIsAdjacent.c"
#include "utils/getPath.c"

int main() {
    Board board = createBoard(5, 5);
    Node *initial = &board.board[2][0];
    Node *final = &board.board[2][4];

    board.board[0][1].isWall = true;
    board.board[1][1].isWall = true;
    board.board[2][1].isWall = true;
    board.board[3][1].isWall = true;
    
    board.board[1][3].isWall = true;
    board.board[2][3].isWall = true;
    board.board[3][3].isWall = true;
    board.board[4][3].isWall = true;

    printWallBoard(&board);
    printf("\n\n");

    openAdjacents(&board, initial, final);

    Node *node = findNodeMinorCost(&board);

    while (checkIfFinalIsAdjacent(&board, node, final) == false) {
        openAdjacents(&board, node, final);
        node = findNodeMinorCost(&board);    
    }
    
    if (checkIfFinalIsAdjacent(&board, node, final)) {
        int arrSize = 0;
        Node **path = getPath(&arrSize, final);

        printPath(&board, path, arrSize);
    }
}