//
// Created by listerily on 2021/7/13.
//

#include "FruitsBarrel.h"

FruitsBarrel::FruitsBarrel(int x, int y) : TileObject("fruits_barrel", x ,y)
{
    tiles = {
            Tile{{":/svl/textures/tiles/0_17_4.png"}, Tile::WalkableType::DISABLE, 0, 0, Tile::DisplayPriority::ON_GROUND}
    };
}