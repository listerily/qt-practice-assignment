//
// Created by listerily on 2021/7/13.
//

#include "WaterBankObject.h"

WaterBankObject::WaterBankObject(int x, int y, int type) : TileObject("water_bank", x, y)
{
    if(type == 0)
    {
        tiles = {
                Tile{{":/svl/textures/tiles/0_9_7.png"}, Tile::WalkableType::DISABLE, 0, 0, Tile::DisplayPriority::SURFACE_BOTTOM},
                Tile{{":/svl/textures/tiles/0_9_8.png", ":/svl/textures/tiles/0_11_9.png"}, Tile::WalkableType::DISABLE, 0, 1, Tile::DisplayPriority::SURFACE_BOTTOM}
        };
        return;
    }
    static const std::vector<std::vector<std::string>> textures = {
            {":/svl/textures/tiles/0_10_7.png"},
            {":/svl/textures/tiles/0_10_8.png"},
            {":/svl/textures/tiles/0_10_10.png"},
            {":/svl/textures/tiles/0_9_10.png"},
            {":/svl/textures/tiles/0_8_10.png"},
            {":/svl/textures/tiles/0_8_8.png"},
            {":/svl/textures/tiles/0_8_7.png"},
            {":/svl/textures/tiles/0_12_8.png"},
            {":/svl/textures/tiles/0_12_9.png"},
            {":/svl/textures/tiles/0_13_8.png"},
            {":/svl/textures/tiles/0_13_9.png"},
            {":/svl/textures/tiles/0_9_11.png"},
            {":/svl/textures/tiles/0_8_11.png"},
            {":/svl/textures/tiles/0_9_12.png"},
            {":/svl/textures/tiles/0_8_12.png"},
    };
    tiles = {
            Tile{textures[type - 1], Tile::WalkableType::DISABLE, 0, 0, Tile::DisplayPriority::SURFACE_BOTTOM},
    };
}
