//
// Created by listerily on 2021/7/11.
//

#include "PathLand.h"

PathLand::PathLand(int x, int y, int aux) : TileObject("path", x, y)
{
    const static std::vector<std::vector<std::string>>textures = {
        {":/svl/textures/tiles/0_1_7.png"},
        {":/svl/textures/tiles/0_1_9.png"},
        {":/svl/textures/tiles/0_1_10.png"},
        {":/svl/textures/tiles/0_2_7.png"},
        {":/svl/textures/tiles/0_2_8.png"},
        {":/svl/textures/tiles/0_2_9.png"},
        {":/svl/textures/tiles/0_2_10.png"},
        {":/svl/textures/tiles/0_3_6.png"},
        {":/svl/textures/tiles/0_3_7.png"},
        {":/svl/textures/tiles/0_4_8.png"},
        {":/svl/textures/tiles/0_4_9.png"},
        {":/svl/textures/tiles/0_5_21.png"},
        {":/svl/textures/tiles/0_5_22.png"},
        {":/svl/textures/tiles/0_5_23.png"},
    };
    tiles = {
            Tile{
                textures[aux],
                false, 0, 0, Tile::DisplayPriority::SURFACE_BOTTOM},
    };
}
