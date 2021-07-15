//
// Created by listerily on 2021/7/14.
//

#include "AutoMobileObject.h"

AutoMobileObject::AutoMobileObject(int x, int y) : TileObject("automobile", x, y)
{
    tiles = {
            {{":/svl/textures/tiles/0_2_76.png"}, Tile::WalkableType::ABLE, -1, -1, Tile::DisplayPriority::SKY},
            {{":/svl/textures/tiles/0_3_76.png"}, Tile::WalkableType::ABLE, +0, -1, Tile::DisplayPriority::SKY},
            {{":/svl/textures/tiles/0_4_76.png"}, Tile::WalkableType::ABLE, +1, -1, Tile::DisplayPriority::SKY},
            {{":/svl/textures/tiles/0_2_77.png"}, Tile::WalkableType::DISABLE, -1, 0, Tile::DisplayPriority::ON_GROUND},
            {{":/svl/textures/tiles/0_3_77.png"}, Tile::WalkableType::DISABLE, +0, 0, Tile::DisplayPriority::ON_GROUND},
            {{":/svl/textures/tiles/0_4_77.png"}, Tile::WalkableType::DISABLE, +1, 0, Tile::DisplayPriority::ON_GROUND},
    };
}
