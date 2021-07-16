//
// Created by listerily on 2021/7/6.
//

#include "GrassLand.h"

GrassLand::GrassLand(int x, int y, int aux) : TileObject("grass", x, y)
{
    const static std::vector<std::vector<std::string>> textures = {
            {":/svl/textures/tiles/0_0_6.png"},
            {":/svl/textures/tiles/0_0_7.png"},
            {":/svl/textures/tiles/0_0_8.png"},
            {":/svl/textures/tiles/0_0_9.png"},
            {":/svl/textures/tiles/0_0_10.png"},

            {":/svl/textures/tiles/0_0_11.png"},
            {":/svl/textures/tiles/0_1_7.png"},
            {":/svl/textures/tiles/0_1_8.png"},
            {":/svl/textures/tiles/0_1_9.png"},
            {":/svl/textures/tiles/0_1_10.png"},

            {":/svl/textures/tiles/0_2_7.png"},
            {":/svl/textures/tiles/0_2_8.png"},
            {":/svl/textures/tiles/0_2_9.png"},
            {":/svl/textures/tiles/0_2_10.png"},
            {":/svl/textures/tiles/0_3_6.png"},

            {":/svl/textures/tiles/0_3_7.png"},
            {":/svl/textures/tiles/0_3_8.png"},
            {":/svl/textures/tiles/0_3_9.png"},
            {":/svl/textures/tiles/0_3_10.png"},
            {":/svl/textures/tiles/0_4_7.png"},

            {":/svl/textures/tiles/0_4_8.png"},
            {":/svl/textures/tiles/0_4_9.png"},
            {":/svl/textures/tiles/0_4_10.png"},
            {":/svl/textures/tiles/0_5_7.png"},
            {":/svl/textures/tiles/0_5_8.png"},

            {":/svl/textures/tiles/0_5_9.png"},
            {":/svl/textures/tiles/0_5_10.png"},
            {":/svl/textures/tiles/0_6_7.png"},
            {":/svl/textures/tiles/0_6_8.png"},
            {":/svl/textures/tiles/0_6_9.png"},

            {":/svl/textures/tiles/0_7_7.png"},
            {":/svl/textures/tiles/0_7_8.png"},
    };
    tiles = {
            Tile{
                    textures[aux],
                    Tile::WalkableType::ABLE, 0, 0, Tile::DisplayPriority::SURFACE_BOTTOM
            }
    };
}
