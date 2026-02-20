#include <stdio.h>

/*
    Tiles have different edges Castle, road, field.
    inside they can have different values, like a blocked road,
    cloister/monestary, or a shield (2x value)

    they also can have a meeple in different positions.
*/
enum t_tileCenter {
    cloister,
    roadblock,
    shield
};

enum t_tileEdge {
    CASTLE,
    ROAD,
    FIELD
};

struct tile {
    t_tileEdge[4] edges; // always in a N E S W notation
    //t_tileCenter centerflags;
}

int main() {
    return 0;
}
