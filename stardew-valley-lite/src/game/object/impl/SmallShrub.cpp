//
// Created by listerily on 2021/7/12.
//

#include <src/game/world/Scene.h>
#include <src/game/world/GameWorld.h>
#include "SmallShrub.h"

SmallShrub::SmallShrub(int x, int y) : TileObject("small_shrub", x, y)
{
    tiles = {
            Tile{{":/svl/textures/tiles/0_13_3.png"}, Tile::WalkableType::ABLE, 0, -1, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_14_3.png"}, Tile::WalkableType::ABLE, 1, -1, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_13_4.png"}, Tile::WalkableType::DISABLE, 0, 0, Tile::DisplayPriority::ON_GROUND},
            Tile{{":/svl/textures/tiles/0_14_4.png"}, Tile::WalkableType::DISABLE, 1, 0, Tile::DisplayPriority::ON_GROUND},
            };
}

void SmallShrub::playerInteract(GameWorld &world, ItemInstance *item, Player &player, Scene &scene, int y, int x)
{
    TileObject::playerInteract(world, item, player, scene, 0, 0);
}