//
// Created by listerily on 2021/7/13.
//

#include "StoneObject.h"

StoneObject::StoneObject(int x, int y, int type) : TileObject("stone", x, y)
{
    tiles = {
            Tile{{type == 0 ? ":/svl/textures/items/4_7_14.png" : ":/svl/textures/items/4_18_18.png"}, Tile::WalkableType::DISABLE, 0, 0, Tile::DisplayPriority::ON_GROUND}
    };
}

std::unique_ptr<Action>
StoneObject::interact(GameWorld &world, ItemInstance *item, Player &player, Scene &scene, int y, int x)
{
    TileObject::interact(world, item, player, scene, 0, 0);
    return nullptr;
}
