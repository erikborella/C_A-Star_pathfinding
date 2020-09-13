#include <stdio.h>

#include "../structs/node.c"

#ifndef GET_PATH_C
#define GET_PATH_C

int _calculatePathSize(Node *final) {
    int counter = 1;
    Node *node = final;

    while (node->lastNode != NULL) {
        counter++;
        node = node->lastNode;
    }

    return counter;
}

Node** getPath(int *arrSize, Node *final) {
    *arrSize =  _calculatePathSize(final);
    Node **path = malloc(sizeof(Node*) * (*arrSize));
    Node *node = final;

    for (int i = 0; i < *arrSize; i++) {
        path[i] = node;
        node = node->lastNode;
    }

    return path;
}

#endif