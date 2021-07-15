//
// Created by listerily on 2021/7/15.
//

#include "HomeStairsObject.h"

HomeStairsObject::HomeStairsObject(int x, int y) : TileObject("home_stairs", x, y)
{
    tiles = {
            {{":/svl/textures/house/6_1_15.png"}, Tile::WalkableType::DISABLE, 0, 0, Tile::DisplayPriority::ON_GROUND}
    };
}
