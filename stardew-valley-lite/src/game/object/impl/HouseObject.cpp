//
// Created by listerily on 2021/7/14.
//

#include "HouseObject.h"

bool HouseObject::ableToInteract() const
{
    return true;
}

HouseObject::HouseObject(int x, int y) : TileObject("house", x, y)
{
    tiles = {
            {{":/svl/textures/tiles/0_0_36"}, Tile::WalkableType::DISABLE, -1, 0, Tile::DisplayPriority::ON_GROUND},
            {{":/svl/textures/tiles/0_1_36"}, Tile::WalkableType::DISABLE, +0, 0, Tile::DisplayPriority::ON_GROUND},
            {{":/svl/textures/tiles/0_2_36"}, Tile::WalkableType::DISABLE, +1, 0, Tile::DisplayPriority::ON_GROUND},
            {{":/svl/textures/tiles/0_3_36"}, Tile::WalkableType::DISABLE, +2, 0, Tile::DisplayPriority::ON_GROUND},

            {{":/svl/textures/tiles/0_0_35"}, Tile::WalkableType::DISABLE, -1, -1, Tile::DisplayPriority::ON_GROUND},
            {{":/svl/textures/tiles/0_1_35"}, Tile::WalkableType::DISABLE, +0, -1, Tile::DisplayPriority::ON_GROUND},
            {{":/svl/textures/tiles/0_2_35"}, Tile::WalkableType::DISABLE, +1, -1, Tile::DisplayPriority::ON_GROUND},
            {{":/svl/textures/tiles/0_3_35"}, Tile::WalkableType::DISABLE, +2, -1, Tile::DisplayPriority::ON_GROUND},

            {{":/svl/textures/tiles/0_0_34"}, Tile::WalkableType::DISABLE, -1, -2, Tile::DisplayPriority::ON_GROUND},
            {{":/svl/textures/tiles/0_1_34"}, Tile::WalkableType::DISABLE, +0, -2, Tile::DisplayPriority::ON_GROUND},
            {{":/svl/textures/tiles/0_2_34"}, Tile::WalkableType::DISABLE, +1, -2, Tile::DisplayPriority::ON_GROUND},
            {{":/svl/textures/tiles/0_3_34"}, Tile::WalkableType::DISABLE, +2, -2, Tile::DisplayPriority::ON_GROUND},

            {{":/svl/textures/tiles/0_0_33"}, Tile::WalkableType::ABLE, -1, -3, Tile::DisplayPriority::SKY},
            {{":/svl/textures/tiles/0_1_33"}, Tile::WalkableType::ABLE, +0, -3, Tile::DisplayPriority::SKY},
            {{":/svl/textures/tiles/0_2_33"}, Tile::WalkableType::ABLE, +1, -3, Tile::DisplayPriority::SKY},
            {{":/svl/textures/tiles/0_3_33"}, Tile::WalkableType::ABLE, +2, -3, Tile::DisplayPriority::SKY},

            {{":/svl/textures/tiles/0_0_32"}, Tile::WalkableType::ABLE, -1, -4, Tile::DisplayPriority::SKY},
            {{":/svl/textures/tiles/0_1_32"}, Tile::WalkableType::ABLE, +0, -4, Tile::DisplayPriority::SKY},
            {{":/svl/textures/tiles/0_2_32"}, Tile::WalkableType::ABLE, +1, -4, Tile::DisplayPriority::SKY},
            {{":/svl/textures/tiles/0_3_32"}, Tile::WalkableType::ABLE, +2, -4, Tile::DisplayPriority::SKY},

            {{":/svl/textures/tiles/0_0_31"}, Tile::WalkableType::ABLE, -1, -5, Tile::DisplayPriority::SKY},
            {{":/svl/textures/tiles/0_1_31"}, Tile::WalkableType::ABLE, +0, -5, Tile::DisplayPriority::SKY},
            {{":/svl/textures/tiles/0_2_31"}, Tile::WalkableType::ABLE, +1, -5, Tile::DisplayPriority::SKY},
            {{":/svl/textures/tiles/0_3_31"}, Tile::WalkableType::ABLE, +2, -5, Tile::DisplayPriority::SKY},

            {{":/svl/textures/tiles/0_0_30"}, Tile::WalkableType::ABLE, -1, -6, Tile::DisplayPriority::SKY},
            {{":/svl/textures/tiles/0_1_30"}, Tile::WalkableType::ABLE, +0, -6, Tile::DisplayPriority::SKY},
            {{":/svl/textures/tiles/0_2_30"}, Tile::WalkableType::ABLE, +1, -6, Tile::DisplayPriority::SKY},
            {{":/svl/textures/tiles/0_3_30"}, Tile::WalkableType::ABLE, +2, -6, Tile::DisplayPriority::SKY},

            {{":/svl/textures/tiles/0_0_29"}, Tile::WalkableType::ABLE, -1, -7, Tile::DisplayPriority::SKY},
            {{":/svl/textures/tiles/0_1_29"}, Tile::WalkableType::ABLE, +0, -7, Tile::DisplayPriority::SKY},
            {{":/svl/textures/tiles/0_2_29"}, Tile::WalkableType::ABLE, +1, -7, Tile::DisplayPriority::SKY},
            {{":/svl/textures/tiles/0_3_29"}, Tile::WalkableType::ABLE, +2, -7, Tile::DisplayPriority::SKY},

            {{":/svl/textures/tiles/0_0_28"}, Tile::WalkableType::ABLE, -1, -8, Tile::DisplayPriority::SKY},
            {{":/svl/textures/tiles/0_1_28"}, Tile::WalkableType::ABLE, +0, -8, Tile::DisplayPriority::SKY},
            {{":/svl/textures/tiles/0_2_28"}, Tile::WalkableType::ABLE, +1, -8, Tile::DisplayPriority::SKY},
            {{":/svl/textures/tiles/0_3_28"}, Tile::WalkableType::ABLE, +2, -8, Tile::DisplayPriority::SKY},

            {{":/svl/textures/tiles/0_0_27"}, Tile::WalkableType::ABLE, -1, -9, Tile::DisplayPriority::SKY},
            {{":/svl/textures/tiles/0_1_27"}, Tile::WalkableType::ABLE, +0, -9, Tile::DisplayPriority::SKY},
            {{":/svl/textures/tiles/0_2_27"}, Tile::WalkableType::ABLE, +1, -9, Tile::DisplayPriority::SKY},
            {{":/svl/textures/tiles/0_3_27"}, Tile::WalkableType::ABLE, +2, -9, Tile::DisplayPriority::SKY},

            {{":/svl/textures/tiles/0_0_26"}, Tile::WalkableType::ABLE, -1, -10, Tile::DisplayPriority::SKY},
            {{":/svl/textures/tiles/0_1_26"}, Tile::WalkableType::ABLE, +0, -10, Tile::DisplayPriority::SKY},
            {{":/svl/textures/tiles/0_2_26"}, Tile::WalkableType::ABLE, +1, -10, Tile::DisplayPriority::SKY},
            {{":/svl/textures/tiles/0_3_26", ":/svl/textures/tiles/0_3_25", ":/svl/textures/tiles/0_3_25"}, Tile::WalkableType::ABLE, +2, -10, Tile::DisplayPriority::SKY},

            {{":/svl/textures/tiles/0_0_25"}, Tile::WalkableType::ABLE, -1, -11, Tile::DisplayPriority::SKY},
            {{":/svl/textures/tiles/0_1_25"}, Tile::WalkableType::ABLE, +0, -11, Tile::DisplayPriority::SKY},
            {{":/svl/textures/tiles/0_2_25"}, Tile::WalkableType::ABLE, +1, -11, Tile::DisplayPriority::SKY},
            {{":/svl/textures/tiles/0_3_25"}, Tile::WalkableType::ABLE, +2, -11, Tile::DisplayPriority::SKY},
    };
}

std::unique_ptr<Action>
HouseObject::interact(GameWorld &world, ItemInstance *instance, Player &p, Scene &scene, int y, int x)
{
    TileObject::interact(world, instance, p, scene, 0, 0);

    world.changeScene("home");
    return nullptr;
}
