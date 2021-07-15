//
// Created by listerily on 2021/7/15.
//

#include "HomeBorderObject.h"

HomeBorderObject::HomeBorderObject(int x, int y) : TileObject("home_border", x, y)
{
    tiles = {
            {{":/svl/textures/house/6_0_0.png"}, Tile::WalkableType::FORCED_DISABLE, 0, 0, Tile::DisplayPriority::BORDER},
    };
}
