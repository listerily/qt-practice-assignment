//
// Created by listerily on 2021/7/14.
//

#include "WoodenPlate.h"

WoodenPlate::WoodenPlate(int x, int y, int type) : TileObject("wooden_plate", x, y)
{
    const static std::vector<std::string> textures = {
            ":/svl/textures/tiles/0_12_77.png",":/svl/textures/tiles/0_14_77.png",":/svl/textures/tiles/0_12_78.png", ":/svl/textures/tiles/0_13_78.png",
    };
    tiles = {
            {{textures[type]}, (type == 1 ? Tile::WalkableType::DISABLE : Tile::WalkableType::ABLE), 0, 0, Tile::DisplayPriority::ON_GROUND}
    };
}
