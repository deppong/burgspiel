#include <stdio.h>

/*
    Tiles have different edges Castle, road, field.
    inside they can have different values, like a blocked road,
    cloister/monestary, or a shield (2x value)

    they also can have a meeple in different positions.
*/

struct road {
    int n1, n2;
};

struct farm {
    int nodes[11];
};

struct city {
    int edges[4];
};

struct tile {
    /*
        0 1 2 3 4
        5       6
        7       8
        9       a
        b c d e f
     */
    struct road roads[4];
    struct farm farms[4];
    struct city cities[2];
};

int main() {
    return 0;
}
