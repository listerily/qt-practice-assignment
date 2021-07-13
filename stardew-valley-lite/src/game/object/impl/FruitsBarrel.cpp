//
// Created by listerily on 2021/7/13.
//

#include "FruitsBarrel.h"

FruitsBarrel::FruitsBarrel(int x, int y) : TileObject("fruits_barrel", x ,y)
{
    tiles = {
            Tile{{":/svl/textures/tiles/0_17_4.png"}, false, 0, 0, Tile::DisplayPriority::ON_GROUND}
    };
}

bool FruitsBarrel::walkable(int, int) const
{
    return false;
}
