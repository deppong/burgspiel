0 1 2 3 4
5       6
7       8
9       a
b c d e f

## tile1
example definition of tile with 1 city 1 road and 2 farms
* city1 -> 7, 8, d (directions to connect, towns typically own the full edge)
* farm1 -> 0, 1 (touching city1)
* farm2 -> 3, 4 (touching city1)
* road1 -> 2

## tile2
more complex tiles require extra info. for example the 4 road tile with a block in the center.

> these roads are all terminating, as they own 1 node
* road1 -> 2; road2 -> 7; road3 -> 8; road2 -> d; 
* farm1 -> 0,1,5
* farm2 -> 3,4,6
* farm3 -> 9,b,c
* farm4 -> a,e,f
--------------------

to connect the two, for example, attaching tile1 to the south edge, the connections would be as follows:
* tile2.road2 <-> tile1 road1 (completed)
* tile2.farm3 <-> tile1.farm1 (touching city1)
* tile2.farm4 <-> tile1.farm2 (touching city1)

game state should be FULLY detached from the tile logic. When a tile is placed it updates the game state.
This allows for pretty solid speed increases, and way less dangling pointers, etc.

```
game.cities {
    city1 {
        meeple = 1;
        size = 1;
        shields = 1;

    }
}
game.farms {
    farm1 {
        *meeples = {1};
        city *adjacent_cities = {city1};
        tile2.farm3/tile1.farm1
    }
    farm2 {
        *meeples = NULL;
        city *adjacent_cities = NULL
```
