//
// Created by listerily on 2021/7/13.
//

#include "LilyPad.h"

LilyPad::LilyPad(int x, int y, int aux) : TileObject("lily_pad", x, y)
{
    tiles = {
            Tile{{aux == 0 ? ":/svl/textures/tiles/0_10_11.png" : ":/svl/textures/tiles/0_10_12.png"}, false, 0, 0, Tile::DisplayPriority::SURFACE_TOP}
    };
}

bool LilyPad::walkable(int, int) const
{
    return false;
}
