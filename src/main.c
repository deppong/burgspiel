#include <stdio.h>
#include <stdint.h>

#define EMPTY -1

typedef enum {
    CITY,
    ROAD,
    FARM
} feat_type_t;

// should probably make them so if you +1 mod 12 it loops over for easy rotating.
typedef enum {
    N, E, S, W,
    NW, NE, EN, ES,
    SE, SW, WS, WN
} dir_t;
typedef struct {
    // type
    feat_type_t type;
    // flags
    int8_t touching_city, cloister;
    dir_t touching[9] // maximum 9 directions of specificity (farm on 3 edges);
} feature_t;

typedef struct {
    // always in the order of NESW
    feat_type_t edges[4];
     // Maximum 9 features (quad road tile)
    feature_t features[9];
} tile_t;


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
