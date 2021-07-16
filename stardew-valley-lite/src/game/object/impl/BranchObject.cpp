//
// Created by listerily on 2021/7/13.
//

#include "BranchObject.h"

#include "../../action/SmashAndGetAction.h"

BranchObject::BranchObject(int x, int y, int type) : TileObject("branch", x, y)
{
    tiles = {
            Tile{{type == 0 ? ":/svl/textures/items/4_6_12.png" : ":/svl/textures/items/4_7_12.png"},
                 Tile::WalkableType::DISABLE, 0, 0, Tile::DisplayPriority::ON_GROUND}
    };
}

std::unique_ptr<Action>
BranchObject::interact(GameWorld &world, ItemInstance *item, Player &player, Scene &scene, int x, int y)
{
    if (item && item->itemMatches(ItemInstance("axe")))
        return std::make_unique<SmashAndGetAction>(*(item->getItem()), ItemInstance("wood", 1), *this, true);
    return TileObject::interact(world, item, player, scene, x, y);
}

bool BranchObject::ableToInteract() const
{
    return true;
}
