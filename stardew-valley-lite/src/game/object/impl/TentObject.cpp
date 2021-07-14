//
// Created by listerily on 2021/7/14.
//

#include "TentObject.h"

TentObject::TentObject(int x, int y) : TileObject("tent", x, y)
{
    tiles = {
            {{":/svl/textures/tiles/0_17_8.png"}, Tile::WalkableType::ABLE, 0, -1, Tile::DisplayPriority::SURFACE_TOP},
            {{":/svl/textures/tiles/0_17_8.png"}, Tile::WalkableType::ABLE, 0, -2, Tile::DisplayPriority::SURFACE_TOP},
            {{":/svl/textures/tiles/0_15_10.png"}, Tile::WalkableType::ABLE, 0, 0, Tile::DisplayPriority::SURFACE_TOP},
            {{":/svl/textures/tiles/0_14_10.png"}, Tile::WalkableType::DISABLE, -1, 0, Tile::DisplayPriority::ON_GROUND},
            {{":/svl/textures/tiles/0_16_10.png"}, Tile::WalkableType::DISABLE, 1, 0, Tile::DisplayPriority::ON_GROUND},
            {{":/svl/textures/tiles/0_14_9.png"}, Tile::WalkableType::DISABLE, -1, -1, Tile::DisplayPriority::SKY},
            {{":/svl/textures/tiles/0_16_9.png"}, Tile::WalkableType::DISABLE, 1, -1, Tile::DisplayPriority::SKY},
            {{":/svl/textures/tiles/0_15_9.png"}, Tile::WalkableType::ABLE, 0, -1, Tile::DisplayPriority::SKY},
            {{":/svl/textures/tiles/0_15_8.png"}, Tile::WalkableType::DISABLE, 0, -2, Tile::DisplayPriority::SKY},
            {{":/svl/textures/tiles/0_14_8.png"}, Tile::WalkableType::DISABLE, -1, -2, Tile::DisplayPriority::SKY},
            {{":/svl/textures/tiles/0_16_8.png"}, Tile::WalkableType::DISABLE, 1, -2, Tile::DisplayPriority::SKY},
            {{":/svl/textures/tiles/0_14_7.png"}, Tile::WalkableType::DISABLE, -1, -3, Tile::DisplayPriority::SKY},
            {{":/svl/textures/tiles/0_16_7.png"}, Tile::WalkableType::DISABLE, 1, -3, Tile::DisplayPriority::SKY},
            {{":/svl/textures/tiles/0_15_7.png"}, Tile::WalkableType::DISABLE, 0, -3, Tile::DisplayPriority::SKY},
            {{":/svl/textures/tiles/0_14_6.png"}, Tile::WalkableType::ABLE, -1, -4, Tile::DisplayPriority::SKY},
            {{":/svl/textures/tiles/0_16_6.png"}, Tile::WalkableType::ABLE, 1, -4, Tile::DisplayPriority::SKY},
            {{":/svl/textures/tiles/0_15_6.png"}, Tile::WalkableType::ABLE, 0, -4, Tile::DisplayPriority::SKY},
            {{":/svl/textures/tiles/0_15_5.png"}, Tile::WalkableType::ABLE, 0, -5, Tile::DisplayPriority::SKY},
    };
}
