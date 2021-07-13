//
// Created by listerily on 2021/7/13.
//

#include "Item.h"

Item::Item(std::string id) : id(std::move(id))
{

}

void Item::playerInteract(Player &, ItemInstance &, TileObject &)
{

}

void Item::playerInteract(Player &, ItemInstance &)
{

}
