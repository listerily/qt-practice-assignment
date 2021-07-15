//
// Created by listerily on 2021/7/13.
//

#include "StoneObject.h"

StoneObject::StoneObject(int x, int y, int) : TileObject("stone", x, y)
{
    tiles = {
            Tile{{":/svl/textures/items/4_7_14.png"}, Tile::WalkableType::DISABLE, 0, 0, Tile::DisplayPriority::ON_GROUND}
    };
}

void StoneObject::playerInteract(Player & player, ItemInstance *item)
{
    TileObject::playerInteract(player, item);
}
