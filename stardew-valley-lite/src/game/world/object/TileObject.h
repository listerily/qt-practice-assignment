//
// Created by listerily on 2021/7/6.
//

#ifndef STARDEW_VALLEY_LITE_TILEOBJECT_H
#define STARDEW_VALLEY_LITE_TILEOBJECT_H


#include <list>
#include <string>

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
    virtual void playerInteract(Player &, Item &, int x, int y);
    virtual bool walkable(int, int) const;
};


#endif //STARDEW_VALLEY_LITE_TILEOBJECT_H