//
// Created by listerily on 2021/7/6.
//

#include "TileObject.h"

#include <utility>

TileObject::TileObject(std::string id, int x, int y) : id(std::move(id)), positionX(x), positionY(y)
{

}

TileObject::~TileObject() = default;

const std::list<Tile> &TileObject::getAllTiles() const
{
    return tiles;
}

void TileObject::playerInteract(Player &, Item &, int x, int y)
{

}

bool TileObject::walkable(int, int) const
{
    return true;
}

void TileObject::afterNight()
{

}

void TileObject::tick()
{

}

std::pair<int, int> TileObject::getPosition() const
{
    return {positionX, positionY};
}
