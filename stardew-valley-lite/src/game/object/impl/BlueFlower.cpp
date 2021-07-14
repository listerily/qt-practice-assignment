//
// Created by listerily on 2021/7/12.
//

#include "BlueFlower.h"

BlueFlower::BlueFlower(int x, int y) : TileObject("blue_flower", x, y)
{
    tiles = {
            Tile{{":/svl/textures/tiles/0_7_12.png"}, Tile::WalkableType::ABLE, 0, 0, Tile::DisplayPriority::SURFACE_MEDIUM}
    };
}