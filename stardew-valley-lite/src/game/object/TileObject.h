//
// Created by listerily on 2021/7/6.
//

#ifndef STARDEW_VALLEY_LITE_TILEOBJECT_H
#define STARDEW_VALLEY_LITE_TILEOBJECT_H


#include <list>
#include <string>
#include <src/game/inventory/ItemInstance.h>

#include "Tile.h"

class Item;
class Player;
class Tile;
class TileObject
{
protected:
    std::list<Tile> tiles;
    std::string id;
    int positionX, positionY;
public:
    explicit TileObject(std::string id, int x, int y);
    virtual ~TileObject();

    virtual std::list<Tile> const& getAllTiles() const;
    virtual void playerInteract(Player &, ItemInstance &);
    virtual bool walkable(int, int) const;
    virtual void afterNight();
    virtual void tick();
    virtual std::pair<int, int> getPosition() const;
};


#endif //STARDEW_VALLEY_LITE_TILEOBJECT_H
