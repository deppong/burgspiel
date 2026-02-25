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

    for(int i = 0; i < 9; i++) {
        if (starting_tile.features[i].type == EMPTY) break;
        for(int j = 0; j < 9; j++) {
            if(starting_tile.features[i].touching[j] == EMPTY) break;
            printf("%d %d\n", starting_tile.features[i].type, starting_tile.features[i].touching[j]);
        }
    }
    return 0;
}
