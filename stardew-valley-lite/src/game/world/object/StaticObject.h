//
// Created by listerily on 2021/7/6.
//

#ifndef STARDEW_VALLEY_LITE_STATICOBJECT_H
#define STARDEW_VALLEY_LITE_STATICOBJECT_H


#include <list>
#include <string>

#include "ObjectTile.h"

class StaticObjectConfig;
class Item;
class Player;
class StaticObject
{
private:
    std::list<ObjectTile> objectTiles;
    StaticObjectConfig const& config;
public:
    explicit StaticObject(StaticObjectConfig const&);
    virtual ~StaticObject();

    virtual std::list<ObjectTile> const& getObjectTiles() const;
    virtual void playerInteract(Player&, Item&);
    virtual bool walkable(int, int) const;
};


#endif //STARDEW_VALLEY_LITE_STATICOBJECT_H
