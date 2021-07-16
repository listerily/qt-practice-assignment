//
// Created by listerily on 2021/7/16.
//

#include "TreeObject.h"

#include "../../action/SmashAndGetAction.h"

TreeObject::TreeObject(std::string id, int x, int y) : TileObject(std::move(id), x, y)
{
    life = 5;
}

bool TreeObject::ableToInteract() const
{
    return true;
}

std::unique_ptr<Action>
TreeObject::interact(GameWorld &world, ItemInstance *instance, Player &player, Scene &scene, int x, int y)
{
    if (life > 0 && instance && instance->itemMatches(ItemInstance("axe")))
    {
        --life;
        if (life == 0)
            return std::make_unique<SmashAndGetAction>(*instance->getItem(), ItemInstance("wood", 8), *this, true);
        return std::make_unique<SmashAndGetAction>(*instance->getItem(), ItemInstance("wood", 0), *this, false);
    }
    return TileObject::interact(world, instance, player, scene, x, y);
}
