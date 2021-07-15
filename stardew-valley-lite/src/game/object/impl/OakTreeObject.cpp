//
// Created by listerily on 2021/7/12.
//

#include <src/game/world/Scene.h>
#include <src/game/world/GameWorld.h>
#include "OakTreeObject.h"

void OakTreeObject::playerInteract(GameWorld &world, ItemInstance *item, Player &player, Scene &scene, int y, int x)
{
    TileObject::playerInteract(world, item, player, scene, 0, 0);
}

OakTreeObject::OakTreeObject(int x, int y) : TileObject("oak_tree", x, y)
{
    tiles = {
        Tile{{":/svl/textures/tiles/0_0_0.png"}, Tile::WalkableType::ABLE, -1, -5, Tile::DisplayPriority::SKY},
        Tile{{":/svl/textures/tiles/0_1_0.png"}, Tile::WalkableType::ABLE, 0, -5, Tile::DisplayPriority::SKY},
        Tile{{":/svl/textures/tiles/0_2_0.png"}, Tile::WalkableType::ABLE, 1, -5, Tile::DisplayPriority::SKY},
        Tile{{":/svl/textures/tiles/0_0_1.png"}, Tile::WalkableType::ABLE, -1, -4, Tile::DisplayPriority::SKY},
        Tile{{":/svl/textures/tiles/0_1_1.png"}, Tile::WalkableType::ABLE, 0, -4, Tile::DisplayPriority::SKY},
        Tile{{":/svl/textures/tiles/0_2_1.png"}, Tile::WalkableType::ABLE, 1, -4, Tile::DisplayPriority::SKY},
        Tile{{":/svl/textures/tiles/0_0_2.png"}, Tile::WalkableType::ABLE, -1, -3, Tile::DisplayPriority::SKY},
        Tile{{":/svl/textures/tiles/0_1_2.png"}, Tile::WalkableType::ABLE, 0, -3, Tile::DisplayPriority::SKY},
        Tile{{":/svl/textures/tiles/0_2_2.png"}, Tile::WalkableType::ABLE, 1, -3, Tile::DisplayPriority::SKY},
        Tile{{":/svl/textures/tiles/0_0_3.png"}, Tile::WalkableType::ABLE, -1, -2, Tile::DisplayPriority::SKY},
        Tile{{":/svl/textures/tiles/0_1_3.png"}, Tile::WalkableType::ABLE, 0, -2, Tile::DisplayPriority::SKY},
        Tile{{":/svl/textures/tiles/0_2_3.png"}, Tile::WalkableType::ABLE, 1, -2, Tile::DisplayPriority::SKY},
        Tile{{":/svl/textures/tiles/0_1_4.png"}, Tile::WalkableType::ABLE, 0, -1, Tile::DisplayPriority::SKY},
        Tile{{":/svl/textures/tiles/0_1_5.png"}, Tile::WalkableType::DISABLE, 0, 0, Tile::DisplayPriority::ON_GROUND},
    };
}
