//
// Created by listerily on 2021/7/13.
//

#include "WaterStakes.h"

WaterStakes::WaterStakes(int x, int y) : TileObject("water_stakes", x, y)
{
    tiles = {
            Tile{{":/svl/textures/tiles/0_10_6.png"}, Tile::WalkableType::DISABLE, 0, 0, Tile::DisplayPriority::SURFACE_MEDIUM}
    };
}
