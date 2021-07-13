//
// Created by listerily on 2021/7/12.
//

#include "SmallStone.h"

SmallStone::SmallStone(int x, int y) : TileObject("small_stone", x, y)
{
    tiles = {
            Tile{{":/svl/textures/tiles/0_7_9.png"}, false, 0, 0, Tile::DisplayPriority::ON_GROUND}
    };
}

bool SmallStone::walkable(int, int) const
{
    return false;
}
