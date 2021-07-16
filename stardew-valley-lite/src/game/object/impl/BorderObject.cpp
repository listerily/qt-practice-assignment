//
// Created by listerily on 2021/7/14.
//

#include "BorderObject.h"

BorderObject::BorderObject(int x, int y, int type) : TileObject("border", x, y)
{
    switch (type)
    {
        case 0:
            tiles = {
                    {{":/svl/textures/tiles/0_15_37.png"}, Tile::WalkableType::FORCED_DISABLE, 0, 0, Tile::DisplayPriority::BORDER},
                    {{":/svl/textures/tiles/0_16_37.png"}, Tile::WalkableType::FORCED_DISABLE, 1, 0, Tile::DisplayPriority::BORDER},
                    {{":/svl/textures/tiles/0_15_38.png"}, Tile::WalkableType::FORCED_DISABLE, 0, 1, Tile::DisplayPriority::BORDER},
                    {{":/svl/textures/tiles/0_16_38.png"}, Tile::WalkableType::ABLE,           1, 1, Tile::DisplayPriority::BORDER},
            };
            break;
        case 1:
            tiles = {
                    {{":/svl/textures/tiles/0_17_37.png"}, Tile::WalkableType::FORCED_DISABLE, 0, 0, Tile::DisplayPriority::BORDER},
                    {{":/svl/textures/tiles/0_18_37.png"}, Tile::WalkableType::FORCED_DISABLE, 1, 0, Tile::DisplayPriority::BORDER},
                    {{":/svl/textures/tiles/0_17_38.png"}, Tile::WalkableType::ABLE,           0, 1, Tile::DisplayPriority::BORDER},
                    {{":/svl/textures/tiles/0_18_38.png"}, Tile::WalkableType::ABLE,           1, 1, Tile::DisplayPriority::BORDER},
            };
            break;
        case 2:
            tiles = {
                    {{":/svl/textures/tiles/0_19_37.png"}, Tile::WalkableType::FORCED_DISABLE, 0, 0, Tile::DisplayPriority::BORDER},
                    {{":/svl/textures/tiles/0_20_37.png"}, Tile::WalkableType::FORCED_DISABLE, 1, 0, Tile::DisplayPriority::BORDER},
                    {{":/svl/textures/tiles/0_19_38.png"}, Tile::WalkableType::ABLE,           0, 1, Tile::DisplayPriority::BORDER},
                    {{":/svl/textures/tiles/0_20_38.png"}, Tile::WalkableType::FORCED_DISABLE, 1, 1, Tile::DisplayPriority::BORDER},
            };
            break;
        case 3:
            tiles = {
                    {{":/svl/textures/tiles/0_19_39.png"}, Tile::WalkableType::ABLE,           0, 0, Tile::DisplayPriority::BORDER},
                    {{":/svl/textures/tiles/0_20_39.png"}, Tile::WalkableType::FORCED_DISABLE, 1, 0, Tile::DisplayPriority::BORDER},
                    {{":/svl/textures/tiles/0_19_40.png"}, Tile::WalkableType::ABLE,           0, 1, Tile::DisplayPriority::BORDER},
                    {{":/svl/textures/tiles/0_20_40.png"}, Tile::WalkableType::FORCED_DISABLE, 1, 1, Tile::DisplayPriority::BORDER},
            };
            break;
        case 4:
            tiles = {
                    {{":/svl/textures/tiles/0_19_41.png"}, Tile::WalkableType::ABLE,           0, 0, Tile::DisplayPriority::BORDER},
                    {{":/svl/textures/tiles/0_20_41.png"}, Tile::WalkableType::FORCED_DISABLE, 1, 0, Tile::DisplayPriority::BORDER},
                    {{":/svl/textures/tiles/0_19_42.png"}, Tile::WalkableType::FORCED_DISABLE, 0, 1, Tile::DisplayPriority::BORDER},
                    {{":/svl/textures/tiles/0_20_42.png"}, Tile::WalkableType::FORCED_DISABLE, 1, 1, Tile::DisplayPriority::BORDER},
            };
            break;
        case 5:
            tiles = {
                    {{":/svl/textures/tiles/0_17_41.png"}, Tile::WalkableType::ABLE,           0, 0, Tile::DisplayPriority::BORDER},
                    {{":/svl/textures/tiles/0_18_41.png"}, Tile::WalkableType::ABLE,           1, 0, Tile::DisplayPriority::BORDER},
                    {{":/svl/textures/tiles/0_17_42.png"}, Tile::WalkableType::FORCED_DISABLE, 0, 1, Tile::DisplayPriority::BORDER},
                    {{":/svl/textures/tiles/0_18_42.png"}, Tile::WalkableType::FORCED_DISABLE, 1, 1, Tile::DisplayPriority::BORDER},
            };
            break;
        case 6:
            tiles = {
                    {{":/svl/textures/tiles/0_15_41.png"}, Tile::WalkableType::FORCED_DISABLE, 0, 0, Tile::DisplayPriority::BORDER},
                    {{":/svl/textures/tiles/0_16_41.png"}, Tile::WalkableType::ABLE,           1, 0, Tile::DisplayPriority::BORDER},
                    {{":/svl/textures/tiles/0_15_42.png"}, Tile::WalkableType::FORCED_DISABLE, 0, 1, Tile::DisplayPriority::BORDER},
                    {{":/svl/textures/tiles/0_16_42.png"}, Tile::WalkableType::FORCED_DISABLE, 1, 1, Tile::DisplayPriority::BORDER},
            };
            break;
        case 7:
            tiles = {
                    {{":/svl/textures/tiles/0_15_39.png"}, Tile::WalkableType::FORCED_DISABLE, 0, 0, Tile::DisplayPriority::BORDER},
                    {{":/svl/textures/tiles/0_16_39.png"}, Tile::WalkableType::ABLE,           1, 0, Tile::DisplayPriority::BORDER},
                    {{":/svl/textures/tiles/0_15_40.png"}, Tile::WalkableType::FORCED_DISABLE, 0, 1, Tile::DisplayPriority::BORDER},
                    {{":/svl/textures/tiles/0_16_40.png"}, Tile::WalkableType::ABLE,           1, 1, Tile::DisplayPriority::BORDER},
            };
            break;
        case 8:
            tiles = {
                    {{":/svl/textures/tiles/0_21_37.png"}, Tile::WalkableType::FORCED_DISABLE, 0, 0, Tile::DisplayPriority::BORDER},
            };
            break;
        case 9:
            tiles = {
                    {{":/svl/textures/tiles/0_21_38.png"}, Tile::WalkableType::FORCED_DISABLE, 0, 0, Tile::DisplayPriority::BORDER},
            };
            break;
        case 10:
            tiles = {
                    {{":/svl/textures/tiles/0_21_39.png"}, Tile::WalkableType::FORCED_DISABLE, 0, 0, Tile::DisplayPriority::BORDER},
            };
            break;
        default:;
    }
}
