//
// Created by listerily on 2021/7/13.
//

#include "BranchObject.h"

#include "../../action/SmashAction.h"

BranchObject::BranchObject(int x, int y, int type) : TileObject("branch", x, y)
{
    tiles = {
            Tile{{type == 0 ? ":/svl/textures/items/4_6_12.png" : ":/svl/textures/items/4_7_12.png"},
                 Tile::WalkableType::DISABLE, 0, 0, Tile::DisplayPriority::ON_GROUND}
    };
}

std::unique_ptr<Action>
BranchObject::interact(GameWorld &world, ItemInstance *item, Player &player, Scene &scene, int y, int x)
{
    TileObject::interact(world, item, player, scene, 0, 0);

    if (item && item->itemMatches(ItemInstance("axe")))
        return std::make_unique<SmashAction>(*(item->getItem()), *ItemInstance("wood").getItem(), *this);
    return nullptr;
}

bool BranchObject::ableToInteract() const
{
    return true;
}
