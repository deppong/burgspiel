#ifndef TILE_H
#define TILE_H
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

#endif
