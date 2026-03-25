#include <stdio.h>
#include "tile.h"

int main() {
    // example starting tile
    tile_t starting_tile = {
        .edges = {CITY, ROAD, FARM, ROAD},
        .features = {
            {.type = CITY, .touching = {N, -1}},
            {.type = ROAD, .touching = {E, W,-1}},
            {.type = FARM, .touching = {EN, WN,-1}, .touching_city=1},
            {.type = FARM, .touching = {ES, S, WS,-1}, .touching_city=0},
            {-1}
        }
    };
    tile_t bare_road = {
        .edges = {FARM, ROAD, FARM, ROAD},
        .features = {
            {.type = ROAD, .touching = {E, W,-1}},
            {.type = FARM, .touching = {EN, N, WN,-1}},
            {.type = FARM, .touching = {ES, S, WS,-1}},
            {-1}
        }
    };

    tile_t board[31*31] = {};
    for (int i = 0; i < 31*31; ++i) {
        board[i] = bare_road;
    }

    #define getidxfromcoord(i,x,y) i*y+x

    // each tile on board
    for (int a = 0; a < 31*31; a++) {
        tile_t t = board[a];
        printf("tile %d: \n", a);
    // all possible features
    for (int i = 0; i < 9; i++) {
        if (t.features[i].type == EMPTY) break;
        printf("feature #%d:\n", i);
        // what are the features edges?
        for (int j = 0; j < 9; j++) {
            if(t.features[i].touching[j] == EMPTY) {printf("\n");break;}
            printf("\t%s %s\n", feat_type_string[t.features[i].type], dir_string[t.features[i].touching[j]]);
        }
    }
    }
    return 0;
}
