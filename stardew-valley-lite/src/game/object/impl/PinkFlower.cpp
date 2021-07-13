//
// Created by listerily on 2021/7/12.
//

#include "PinkFlower.h"

PinkFlower::PinkFlower(int x, int y) : TileObject("pink_flower", x, y)
{
    tiles = {
            Tile{{":/svl/textures/tiles/0_7_10.png"}, false, 0, 0, Tile::DisplayPriority::ON_GROUND}
    };
}
