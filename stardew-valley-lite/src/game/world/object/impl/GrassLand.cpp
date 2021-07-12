//
// Created by listerily on 2021/7/6.
//

#include "GrassLand.h"

GrassLand::GrassLand(int x, int y, int aux) : TileObject("grass", x, y)
{
    const static std::vector<std::vector<std::string>> textures = {
            {":/svl/textures/tiles/0_0_6.png"},
            {":/svl/textures/tiles/0_0_7.png"},
            {":/svl/textures/tiles/0_0_11.png"},
            {":/svl/textures/tiles/0_0_12.png"},
            {":/svl/textures/tiles/0_0_13.png"},
            {":/svl/textures/tiles/0_0_14.png"},
            {":/svl/textures/tiles/0_0_15.png"},
            {":/svl/textures/tiles/0_0_16.png"},
            {":/svl/textures/tiles/0_1_11.png"},
            {":/svl/textures/tiles/0_1_12.png"},
            {":/svl/textures/tiles/0_1_13.png"},
            {":/svl/textures/tiles/0_1_14.png"},
            {":/svl/textures/tiles/0_1_15.png"},
            {":/svl/textures/tiles/0_1_16.png"},
    };
    tiles = {
           Tile{
                   textures[aux],
                   false, 0, 0, Tile::DisplayPriority::SURFACE_BOTTOM
           }
    };
}
