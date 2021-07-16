//
// Created by listerily on 2021/7/12.
//

#include "LargeShrub.h"

std::unique_ptr<Action>
LargeShrub::interact(GameWorld &world, ItemInstance *item, Player &player, Scene &scene, int x, int y)
{
    TileObject::interact(world, item, player, scene, x, y);
    return nullptr;
}

LargeShrub::LargeShrub(int x, int y) : TileObject("large_shrub", x, y)
{
    tiles = {
            Tile{{":/svl/textures/tiles/0_13_0.png"}, Tile::WalkableType::ABLE, 0, -2, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_14_0.png"}, Tile::WalkableType::ABLE, 1, -2, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_15_0.png"}, Tile::WalkableType::ABLE, 2, -2, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_13_1.png"}, Tile::WalkableType::ABLE, 0, -1, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_14_1.png"}, Tile::WalkableType::ABLE, 1, -1, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_15_1.png"}, Tile::WalkableType::ABLE, 2, -1, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_13_2.png"}, Tile::WalkableType::DISABLE, 0, 0,
                 Tile::DisplayPriority::ON_GROUND},
            Tile{{":/svl/textures/tiles/0_14_2.png"}, Tile::WalkableType::DISABLE, 1, 0,
                 Tile::DisplayPriority::ON_GROUND},
            Tile{{":/svl/textures/tiles/0_15_2.png"}, Tile::WalkableType::DISABLE, 2, 0,
                 Tile::DisplayPriority::ON_GROUND},
    };
}
