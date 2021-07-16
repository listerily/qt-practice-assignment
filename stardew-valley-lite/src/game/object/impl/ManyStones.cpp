//
// Created by listerily on 2021/7/12.
//

#include "ManyStones.h"

ManyStones::ManyStones(int x, int y) : TileObject("many_stones", x, y)
{
    tiles = {
            Tile{{":/svl/textures/tiles/0_7_11.png"}, Tile::WalkableType::DISABLE, 0, 0,
                 Tile::DisplayPriority::SURFACE_TOP}
    };
}
