//
// Created by listerily on 2021/7/13.
//

#include "Item.h"

Item::Item(std::string id) : id(std::move(id))
{

}

std::unique_ptr<Action> Item::onInteract(Player &, ItemInstance &, TileObject &) const
{
    return nullptr;
}

std::unique_ptr<Action> Item::interact(Player &, ItemInstance &) const
{
    return nullptr;
}

bool Item::hideWhenCarrying() const
{
    return true;
}
