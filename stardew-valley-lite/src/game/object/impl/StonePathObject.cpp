//
// Created by listerily on 2021/7/14.
//

#include "StonePathObject.h"

StonePathObject::StonePathObject(int x, int y, int type) : TileObject("stone_path", x, y)
{
    const static std::vector<std::string> textures = {
            ":/svl/textures/tiles/0_14_78.png", ":/svl/textures/tiles/0_15_78.png", ":/svl/textures/tiles/0_16_78.png",
    };
    tiles = {
            {{textures[type]}, Tile::WalkableType::ABLE, 0, 0, Tile::DisplayPriority::SURFACE_TOP}
    };
}
