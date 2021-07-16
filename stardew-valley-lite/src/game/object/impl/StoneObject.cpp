//
// Created by listerily on 2021/7/13.
//

#include "StoneObject.h"

#include "../../action/SmashAndGetAction.h"

StoneObject::StoneObject(int x, int y, int type) : TileObject("stone", x, y)
{
    tiles = {
            Tile{{type == 0 ? ":/svl/textures/items/4_7_14.png" : ":/svl/textures/items/4_18_18.png"},
                 Tile::WalkableType::DISABLE, 0, 0, Tile::DisplayPriority::ON_GROUND}
    };
}

std::unique_ptr<Action>
StoneObject::interact(GameWorld &world, ItemInstance *item, Player &player, Scene &scene, int x, int y)
{
    if (item && item->itemMatches(ItemInstance("pickaxe")))
        return std::make_unique<SmashAndGetAction>(*(item->getItem()), ItemInstance("stone", 1), *this, true);
    return TileObject::interact(world, item, player, scene, x, y);
}

bool StoneObject::ableToInteract() const
{
    return true;
}
