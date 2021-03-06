//
// Created by listerily on 2021/7/15.
//

#include "HouseBackgroundObject.h"

HouseBackgroundObject::HouseBackgroundObject(int x, int y) : TileObject("house_background", x, y)
{
    tiles = {
            {{":/svl/textures/house/6_0_0.png"},   Tile::WalkableType::DISABLE, 0,  0,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_1_0.png"},   Tile::WalkableType::DISABLE, 1,  0,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_2_0.png"},   Tile::WalkableType::DISABLE, 2,  0,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_3_0.png"},   Tile::WalkableType::DISABLE, 3,  0,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_4_0.png"},   Tile::WalkableType::DISABLE, 4,  0,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_5_0.png"},   Tile::WalkableType::DISABLE, 5,  0,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_6_0.png"},   Tile::WalkableType::DISABLE, 6,  0,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_7_0.png"},   Tile::WalkableType::DISABLE, 7,  0,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_8_0.png"},   Tile::WalkableType::DISABLE, 8,  0,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_9_0.png"},   Tile::WalkableType::DISABLE, 9,  0,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_10_0.png"},  Tile::WalkableType::DISABLE, 10, 0,  Tile::DisplayPriority::SKY},

            {{":/svl/textures/house/6_0_1.png"},   Tile::WalkableType::DISABLE, 0,  1,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_1_1.png"},   Tile::WalkableType::DISABLE, 1,  1,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_2_1.png"},   Tile::WalkableType::DISABLE, 2,  1,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_3_1.png"},   Tile::WalkableType::DISABLE, 3,  1,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_4_1.png"},   Tile::WalkableType::DISABLE, 4,  1,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_5_1.png"},   Tile::WalkableType::DISABLE, 5,  1,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_6_1.png"},   Tile::WalkableType::DISABLE, 6,  1,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_7_1.png"},   Tile::WalkableType::DISABLE, 7,  1,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_8_1.png"},   Tile::WalkableType::DISABLE, 8,  1,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_9_1.png"},   Tile::WalkableType::DISABLE, 9,  1,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_10_1.png"},  Tile::WalkableType::DISABLE, 10, 1,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_11_1.png"},  Tile::WalkableType::DISABLE, 11, 1,  Tile::DisplayPriority::SKY},

            {{":/svl/textures/house/6_0_1.png"},   Tile::WalkableType::DISABLE, 0,  1,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_1_1.png"},   Tile::WalkableType::DISABLE, 1,  1,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_2_1.png"},   Tile::WalkableType::DISABLE, 2,  1,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_3_1.png"},   Tile::WalkableType::DISABLE, 3,  1,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_4_1.png"},   Tile::WalkableType::DISABLE, 4,  1,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_5_1.png"},   Tile::WalkableType::DISABLE, 5,  1,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_6_1.png"},   Tile::WalkableType::DISABLE, 6,  1,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_7_1.png"},   Tile::WalkableType::DISABLE, 7,  1,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_8_1.png"},   Tile::WalkableType::DISABLE, 8,  1,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_9_1.png"},   Tile::WalkableType::DISABLE, 9,  1,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_10_1.png"},  Tile::WalkableType::DISABLE, 10, 1,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_11_1.png"},  Tile::WalkableType::DISABLE, 11, 1,  Tile::DisplayPriority::SKY},

            {{":/svl/textures/house/6_0_2.png"},   Tile::WalkableType::DISABLE, 0,  2,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_1_2.png"},   Tile::WalkableType::DISABLE, 1,  2,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_2_2.png"},   Tile::WalkableType::DISABLE, 2,  2,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_3_2.png"},   Tile::WalkableType::DISABLE, 3,  2,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_4_2.png"},   Tile::WalkableType::DISABLE, 4,  2,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_5_2.png"},   Tile::WalkableType::DISABLE, 5,  2,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_6_2.png"},   Tile::WalkableType::DISABLE, 6,  2,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_7_2.png"},   Tile::WalkableType::DISABLE, 7,  2,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_8_2.png"},   Tile::WalkableType::DISABLE, 8,  2,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_9_2.png"},   Tile::WalkableType::DISABLE, 9,  2,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_10_2.png"},  Tile::WalkableType::DISABLE, 10, 2,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_11_2.png"},  Tile::WalkableType::DISABLE, 11, 2,  Tile::DisplayPriority::SKY},

            {{":/svl/textures/house/6_0_3.png"},   Tile::WalkableType::DISABLE, 0,  3,  Tile::DisplayPriority::ON_GROUND},
            {{":/svl/textures/house/6_1_3.png"},   Tile::WalkableType::DISABLE, 1,  3,  Tile::DisplayPriority::ON_GROUND},
            {{":/svl/textures/house/6_2_3.png"},   Tile::WalkableType::DISABLE, 2,  3,  Tile::DisplayPriority::ON_GROUND},
            {{":/svl/textures/house/6_3_3.png"},   Tile::WalkableType::DISABLE, 3,  3,  Tile::DisplayPriority::ON_GROUND},
            {{":/svl/textures/house/6_4_3.png"},   Tile::WalkableType::DISABLE, 4,  3,  Tile::DisplayPriority::ON_GROUND},
            {{":/svl/textures/house/6_5_3.png"},   Tile::WalkableType::DISABLE, 5,  3,  Tile::DisplayPriority::ON_GROUND},
            {{":/svl/textures/house/6_6_3.png"},   Tile::WalkableType::DISABLE, 6,  3,  Tile::DisplayPriority::ON_GROUND},
            {{":/svl/textures/house/6_7_3.png"},   Tile::WalkableType::DISABLE, 7,  3,  Tile::DisplayPriority::ON_GROUND},
            {{":/svl/textures/house/6_8_3.png"},   Tile::WalkableType::DISABLE, 8,  3,  Tile::DisplayPriority::ON_GROUND},
            {{":/svl/textures/house/6_9_3.png"},   Tile::WalkableType::DISABLE, 9,  3,  Tile::DisplayPriority::ON_GROUND},
            {{":/svl/textures/house/6_10_3.png"},  Tile::WalkableType::DISABLE, 10, 3,  Tile::DisplayPriority::ON_GROUND},
            {{":/svl/textures/house/6_11_3.png"},  Tile::WalkableType::DISABLE, 11, 3,  Tile::DisplayPriority::ON_GROUND},

            {{":/svl/textures/house/6_0_4.png"},   Tile::WalkableType::DISABLE, 0,  4,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_1_4.png"},   Tile::WalkableType::ABLE,    1,  4,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_2_4.png"},   Tile::WalkableType::ABLE,    2,  4,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_3_4.png"},   Tile::WalkableType::ABLE,    3,  4,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_4_4.png"},   Tile::WalkableType::ABLE,    4,  4,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_5_4.png"},   Tile::WalkableType::ABLE,    5,  4,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_6_4.png"},   Tile::WalkableType::ABLE,    6,  4,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_7_4.png"},   Tile::WalkableType::ABLE,    7,  4,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_8_4.png"},   Tile::WalkableType::DISABLE, 8,  4,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_9_4.png"},   Tile::WalkableType::DISABLE, 9,  4,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_10_4.png"},  Tile::WalkableType::DISABLE, 10, 4,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_11_4.png"},  Tile::WalkableType::DISABLE, 11, 4,  Tile::DisplayPriority::SURFACE_BOTTOM},

            {{":/svl/textures/house/6_0_5.png"},   Tile::WalkableType::DISABLE, 0,  5,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_0_5.png"},   Tile::WalkableType::DISABLE, 0,  6,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_0_5.png"},   Tile::WalkableType::DISABLE, 0,  7,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_0_5.png"},   Tile::WalkableType::DISABLE, 0,  8,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_0_5.png"},   Tile::WalkableType::DISABLE, 0,  9,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_0_10.png"},  Tile::WalkableType::DISABLE, 0,  10, Tile::DisplayPriority::SKY},

            {{":/svl/textures/house/6_1_10.png"},  Tile::WalkableType::ABLE,    1,  10, Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_2_10.png"},  Tile::WalkableType::ABLE,    2,  10, Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_1_10.png"},  Tile::WalkableType::ABLE,    3,  10, Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_2_10.png"},  Tile::WalkableType::ABLE,    4,  10, Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_1_10.png"},  Tile::WalkableType::ABLE,    5,  10, Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_2_10.png"},  Tile::WalkableType::ABLE,    6,  10, Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_1_10.png"},  Tile::WalkableType::ABLE,    7,  10, Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_2_10.png"},  Tile::WalkableType::ABLE,    8,  10, Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_1_10.png"},  Tile::WalkableType::ABLE,    9,  10, Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_2_10.png"},  Tile::WalkableType::ABLE,    10, 10, Tile::DisplayPriority::SURFACE_BOTTOM},

            {{":/svl/textures/house/6_0_11.png"},  Tile::WalkableType::ABLE,    1,  10, Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_6_11.png"},  Tile::WalkableType::ABLE,    2,  10, Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_6_11.png"},  Tile::WalkableType::ABLE,    3,  10, Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_6_11.png"},  Tile::WalkableType::ABLE,    4,  10, Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_6_11.png"},  Tile::WalkableType::ABLE,    5,  10, Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_6_11.png"},  Tile::WalkableType::ABLE,    6,  10, Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_6_11.png"},  Tile::WalkableType::ABLE,    7,  10, Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_6_11.png"},  Tile::WalkableType::ABLE,    8,  10, Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_6_11.png"},  Tile::WalkableType::ABLE,    9,  10, Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_11_0.png"},  Tile::WalkableType::ABLE,    10, 10, Tile::DisplayPriority::SKY},

            {{":/svl/textures/house/6_11_5.png"},  Tile::WalkableType::DISABLE, 11, 5,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_11_5.png"},  Tile::WalkableType::DISABLE, 11, 6,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_11_5.png"},  Tile::WalkableType::DISABLE, 11, 7,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_11_5.png"},  Tile::WalkableType::DISABLE, 11, 8,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_11_5.png"},  Tile::WalkableType::DISABLE, 11, 9,  Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_11_10.png"}, Tile::WalkableType::DISABLE, 11, 10, Tile::DisplayPriority::SKY},

            {{":/svl/textures/house/6_1_7.png"},   Tile::WalkableType::ABLE,    1,  5,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_1_8.png"},   Tile::WalkableType::ABLE,    1,  6,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_1_9.png"},   Tile::WalkableType::ABLE,    1,  7,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_2_7.png"},   Tile::WalkableType::ABLE,    2,  5,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_2_8.png"},   Tile::WalkableType::ABLE,    2,  6,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_2_9.png"},   Tile::WalkableType::ABLE,    2,  7,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_10_5.png"},  Tile::WalkableType::ABLE,    3,  5,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_10_6.png"},  Tile::WalkableType::ABLE,    3,  6,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_10_7.png"},  Tile::WalkableType::ABLE,    3,  7,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_1_7.png"},   Tile::WalkableType::ABLE,    4,  5,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_1_8.png"},   Tile::WalkableType::ABLE,    4,  6,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_1_9.png"},   Tile::WalkableType::ABLE,    4,  7,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_2_7.png"},   Tile::WalkableType::ABLE,    5,  5,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_2_8.png"},   Tile::WalkableType::ABLE,    5,  6,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_2_9.png"},   Tile::WalkableType::ABLE,    5,  7,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_10_5.png"},  Tile::WalkableType::ABLE,    6,  5,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_10_6.png"},  Tile::WalkableType::ABLE,    6,  6,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_10_7.png"},  Tile::WalkableType::ABLE,    6,  7,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_1_7.png"},   Tile::WalkableType::ABLE,    7,  5,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_1_8.png"},   Tile::WalkableType::ABLE,    7,  6,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_1_9.png"},   Tile::WalkableType::ABLE,    7,  7,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_2_7.png"},   Tile::WalkableType::ABLE,    8,  5,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_2_8.png"},   Tile::WalkableType::ABLE,    8,  6,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_2_9.png"},   Tile::WalkableType::ABLE,    8,  7,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_10_5.png"},  Tile::WalkableType::ABLE,    9,  5,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_10_6.png"},  Tile::WalkableType::ABLE,    9,  6,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_10_7.png"},  Tile::WalkableType::ABLE,    9,  7,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_1_7.png"},   Tile::WalkableType::ABLE,    10, 5,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_1_8.png"},   Tile::WalkableType::ABLE,    10, 6,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_1_9.png"},   Tile::WalkableType::ABLE,    10, 7,  Tile::DisplayPriority::SURFACE_BOTTOM},

            {{":/svl/textures/house/6_1_7.png"},   Tile::WalkableType::ABLE,    1,  8,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_1_8.png"},   Tile::WalkableType::ABLE,    1,  9,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_2_7.png"},   Tile::WalkableType::ABLE,    2,  8,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_2_8.png"},   Tile::WalkableType::ABLE,    2,  9,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_10_5.png"},  Tile::WalkableType::ABLE,    3,  8,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_10_6.png"},  Tile::WalkableType::ABLE,    3,  9,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_1_7.png"},   Tile::WalkableType::ABLE,    4,  8,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_1_8.png"},   Tile::WalkableType::ABLE,    4,  9,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_2_7.png"},   Tile::WalkableType::ABLE,    5,  8,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_2_8.png"},   Tile::WalkableType::ABLE,    5,  9,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_10_5.png"},  Tile::WalkableType::ABLE,    6,  8,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_10_6.png"},  Tile::WalkableType::ABLE,    6,  9,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_1_7.png"},   Tile::WalkableType::ABLE,    7,  8,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_1_8.png"},   Tile::WalkableType::ABLE,    7,  9,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_2_7.png"},   Tile::WalkableType::ABLE,    8,  8,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_2_8.png"},   Tile::WalkableType::ABLE,    8,  9,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_10_5.png"},  Tile::WalkableType::ABLE,    9,  8,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_10_6.png"},  Tile::WalkableType::ABLE,    9,  9,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_1_7.png"},   Tile::WalkableType::ABLE,    10, 8,  Tile::DisplayPriority::SURFACE_BOTTOM},
            {{":/svl/textures/house/6_1_8.png"},   Tile::WalkableType::ABLE,    10, 9,  Tile::DisplayPriority::SURFACE_BOTTOM},


    };

}

bool HouseBackgroundObject::ableToInteract() const
{
    return false;
}
