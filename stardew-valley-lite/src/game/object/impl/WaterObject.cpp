//
// Created by listerily on 2021/7/12.
//

#include "WaterObject.h"

WaterObject::WaterObject(int x, int y) : TileObject("water", x, y)
{
    tiles = {
            Tile{
                    std::vector<std::string>{":/svl/textures/tiles/0_8_13.png", ":/svl/textures/tiles/0_9_13.png",
                                             ":/svl/textures/tiles/0_10_13.png", ":/svl/textures/tiles/0_11_13.png"},
                    Tile::WalkableType::DISABLE, 0, 0, Tile::DisplayPriority::UNDERGROUND
            }
    };
}