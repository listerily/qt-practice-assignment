//
// Created by listerily on 2021/7/13.
//

#include "FenceObject.h"

FenceObject::FenceObject(int x, int y, bool h, int type) : TileObject("fence", x, y)
{
    if (h)
    {
        switch (type)
        {
            case 0:
                tiles = {
                        {{":/svl/textures/tiles/0_8_15.png"}, Tile::WalkableType::DISABLE, 0, 0,  Tile::DisplayPriority::ON_GROUND},
                        {{":/svl/textures/tiles/0_8_14.png"}, Tile::WalkableType::ABLE,    0, -1, Tile::DisplayPriority::SKY}
                };
                break;
            case 1:
                tiles = {
                        {{":/svl/textures/tiles/0_9_15.png"}, Tile::WalkableType::DISABLE, 0, 0,  Tile::DisplayPriority::ON_GROUND},
                        {{":/svl/textures/tiles/0_9_14.png"}, Tile::WalkableType::ABLE,    0, -1, Tile::DisplayPriority::SKY}
                };
                break;
            case 2:
                tiles = {
                        {{":/svl/textures/tiles/0_10_15.png"}, Tile::WalkableType::DISABLE, 0, 0,  Tile::DisplayPriority::ON_GROUND},
                        {{":/svl/textures/tiles/0_10_14.png"}, Tile::WalkableType::ABLE,    0, -1, Tile::DisplayPriority::SKY}
                };
                break;
            case 3:
                tiles = {
                        {{":/svl/textures/tiles/0_9_16.png"}, Tile::WalkableType::ABLE,    0, -1, Tile::DisplayPriority::SKY},
                        {{":/svl/textures/tiles/0_9_17.png"}, Tile::WalkableType::DISABLE, 0, 0,  Tile::DisplayPriority::ON_GROUND},
                };
                break;
            default:;
        }
    } else
    {
        switch (type)
        {
            case 2:
                tiles = {
                        {{":/svl/textures/tiles/0_11_16.png"}, Tile::WalkableType::DISABLE, 0, -1, Tile::DisplayPriority::SKY},
                        {{":/svl/textures/tiles/0_11_17.png"}, Tile::WalkableType::DISABLE, 0, 0,  Tile::DisplayPriority::ON_GROUND}
                };
                break;
            case 1:
                tiles = {
                        {{":/svl/textures/tiles/0_11_15.png"}, Tile::WalkableType::DISABLE, 0, 0, Tile::DisplayPriority::ON_GROUND},
                };
                break;
            case 0:
                tiles = {
                        {{":/svl/textures/tiles/0_11_14.png"}, Tile::WalkableType::ABLE, 0, 0, Tile::DisplayPriority::SKY},
                };
                break;
            default:;
        }
    }
}
