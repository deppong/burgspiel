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

    tile_t board[2] = {starting_tile, bare_road};

    for (int a = 0; a < 2; a++) {
        tile_t t = board[a];
        printf("tile %d: \n", a);
    for (int i = 0; i < 9; i++) {
        if (t.features[i].type == EMPTY) break;
        for (int j = 0; j < 9; j++) {
            if(t.features[i].touching[j] == EMPTY) break;
            printf("\t%s %d\n", feat_type_string[t.features[i].type], t.features[i].touching[j]);
        }
    }
    }
    return 0;
}
