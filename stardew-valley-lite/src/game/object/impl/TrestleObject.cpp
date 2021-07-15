//
// Created by listerily on 2021/7/14.
//

#include "TrestleObject.h"

TrestleObject::TrestleObject(int x, int y, int type) : TileObject("trestle", x, y)
{
    switch (type)
    {
        case 0:
            tiles = {
                    {{":/svl/textures/tiles/0_11_65"}, Tile::WalkableType::DISABLE, -3, 0, Tile::DisplayPriority::SURFACE_TOP},
                    {{":/svl/textures/tiles/0_12_65"}, Tile::WalkableType::FORCED_ABLE, -2, 0, Tile::DisplayPriority::SURFACE_TOP},
                    {{":/svl/textures/tiles/0_13_65"}, Tile::WalkableType::FORCED_ABLE, -1, 0, Tile::DisplayPriority::SURFACE_TOP},
                    {{":/svl/textures/tiles/0_14_65"}, Tile::WalkableType::FORCED_ABLE, +0, 0, Tile::DisplayPriority::SURFACE_TOP},
                    {{":/svl/textures/tiles/0_15_65"}, Tile::WalkableType::DISABLE, +1, 0, Tile::DisplayPriority::SURFACE_TOP},
            };
            break;
        case 1:
            tiles = {
                    {{":/svl/textures/tiles/0_11_66"}, Tile::WalkableType::DISABLE, -3, 0, Tile::DisplayPriority::SURFACE_TOP},
                    {{":/svl/textures/tiles/0_12_66"}, Tile::WalkableType::FORCED_ABLE, -2, 0, Tile::DisplayPriority::SURFACE_TOP},
                    {{":/svl/textures/tiles/0_13_66"}, Tile::WalkableType::FORCED_ABLE, -1, 0, Tile::DisplayPriority::SURFACE_TOP},
                    {{":/svl/textures/tiles/0_14_66"}, Tile::WalkableType::FORCED_ABLE, +0, 0, Tile::DisplayPriority::SURFACE_TOP},
                    {{":/svl/textures/tiles/0_15_66"}, Tile::WalkableType::DISABLE, +1, 0, Tile::DisplayPriority::SURFACE_TOP},
            };
            break;
        case 2:
            tiles = {
                    {{":/svl/textures/tiles/0_11_67"}, Tile::WalkableType::DISABLE, -3, 0, Tile::DisplayPriority::SURFACE_TOP},
                    {{":/svl/textures/tiles/0_12_67"}, Tile::WalkableType::FORCED_ABLE, -2, 0, Tile::DisplayPriority::SURFACE_TOP},
                    {{":/svl/textures/tiles/0_13_67"}, Tile::WalkableType::FORCED_ABLE, -1, 0, Tile::DisplayPriority::SURFACE_TOP},
                    {{":/svl/textures/tiles/0_14_67"}, Tile::WalkableType::FORCED_ABLE, +0, 0, Tile::DisplayPriority::SURFACE_TOP},
                    {{":/svl/textures/tiles/0_15_67"}, Tile::WalkableType::DISABLE, +1, 0, Tile::DisplayPriority::SURFACE_TOP},
                    {{":/svl/textures/tiles/0_11_68"}, Tile::WalkableType::DISABLE, -3, 1, Tile::DisplayPriority::SURFACE_TOP},
                    {{":/svl/textures/tiles/0_12_68"}, Tile::WalkableType::DISABLE, -2, 1, Tile::DisplayPriority::SURFACE_TOP},
                    {{":/svl/textures/tiles/0_13_68"}, Tile::WalkableType::DISABLE, -1, 1, Tile::DisplayPriority::SURFACE_TOP},
                    {{":/svl/textures/tiles/0_14_68"}, Tile::WalkableType::DISABLE, +0, 1, Tile::DisplayPriority::SURFACE_TOP},
                    {{":/svl/textures/tiles/0_15_68"}, Tile::WalkableType::DISABLE, +1, 1, Tile::DisplayPriority::SURFACE_TOP},
            };
            break;
        default:
            ;
    }
}
