//
// Created by listerily on 2021/7/11.
//

#include "PathLand.h"

PathLand::PathLand(int x, int y) : TileObject("path", x, y)
{
    tiles = {
            Tile{{":/svl/textures/tiles/0_1_7.png"}, false, 0, 0, Tile::DisplayPriority::SURFACE_BOTTOM},
    };
}
