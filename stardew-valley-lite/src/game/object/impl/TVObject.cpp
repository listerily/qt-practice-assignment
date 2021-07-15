//
// Created by listerily on 2021/7/15.
//

#include "TVObject.h"

TVObject::TVObject(int x, int y) : TileObject("tv", x, y)
{
    tiles = {
            {{":/svl/textures/house/6_6_12.png"}, Tile::WalkableType::ABLE, 0, -2, Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_7_12.png"}, Tile::WalkableType::ABLE, 1, -2, Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_6_13.png"}, Tile::WalkableType::ABLE, 0, -1, Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_7_13.png"}, Tile::WalkableType::ABLE, 1, -1, Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_6_14.png"}, Tile::WalkableType::DISABLE, 0, 0, Tile::DisplayPriority::ON_GROUND},
            {{":/svl/textures/house/6_7_14.png"}, Tile::WalkableType::DISABLE, 1, 0, Tile::DisplayPriority::ON_GROUND},

    };
}
