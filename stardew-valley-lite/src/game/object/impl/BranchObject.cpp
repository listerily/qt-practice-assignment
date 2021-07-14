//
// Created by listerily on 2021/7/13.
//

#include "BranchObject.h"

BranchObject::BranchObject(int x, int y, int type) : TileObject("branch", x, y)
{
    tiles = {
            Tile{{type == 0 ? ":/svl/textures/items/4_6_12.png" : ":/svl/textures/items/4_7_12.png"}, Tile::WalkableType::DISABLE, 0, 0, Tile::DisplayPriority::ON_GROUND}
    };
}

void BranchObject::playerInteract(Player & player, ItemInstance *item)
{
    TileObject::playerInteract(player, item);
}
