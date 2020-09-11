#include "../structs/position.c"

#ifndef DISTANCE_CALCULATOR_C
#define DISTANCE_CALCULATOR_C

int euclidianDistance(Position position1, Position position2) {
    double a = pow(abs(position2.x - position1.x), 2);
    double b = pow(abs(position2.y - position1.y), 2);
    
    double c = sqrt(a + b);

    int distance = floor(c*10);
    return distance;
}

void _calculateGCost(Node *node) {
    Node *lastNode = node->lastNode;

    node->distances.gCost = euclidianDistance(node->position, lastNode->position);

    node->distances.gCost += lastNode->distances.gCost;
}

void _calculateHCost(Node *node, Node *finalNode) {
    node->distances.hCost = euclidianDistance(node->position, finalNode->position);
}

void calculateDistances(Node *node, Node *finalNode) {
    _calculateGCost(node);
    _calculateHCost(node, finalNode);
    node->distances.totalCost = node->distances.gCost + node->distances.hCost;
}

#endif