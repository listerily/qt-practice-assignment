//
// Created by listerily on 2021/7/6.
//

#include "StaticObject.h"

StaticObject::StaticObject(const StaticObjectConfig & config) : config(config)
{

}

StaticObject::~StaticObject()
{

}

std::list<ObjectTile> const &StaticObject::getObjectTiles() const
{
    return objectTiles;
}

void StaticObject::playerInteract(Player &, Item &)
{

}

bool StaticObject::walkable(int, int) const
{
    return true;
}
