#ifndef DISTANCES_C
#define DISTANCES_C

struct Distances {
    //distance to initial node
    int gCost;

    //distance to final node
    int hCost;
    
    //gCost + hCost
    int totalCost;
};

typedef struct Distances Distances;

#endif