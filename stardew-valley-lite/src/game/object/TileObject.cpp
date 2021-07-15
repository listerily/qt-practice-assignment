//
// Created by listerily on 2021/7/6.
//

#include "TileObject.h"

#include <utility>
#include <src/game/world/Scene.h>
#include <src/game/world/GameWorld.h>

TileObject::TileObject(std::string id, int x, int y) : id(std::move(id)), positionX(x), positionY(y)
{

}

TileObject::~TileObject() = default;

const std::list<Tile> &TileObject::getAllTiles() const
{
    return tiles;
}

void TileObject::playerInteract(GameWorld &world, ItemInstance *instance, Player &player, Scene &scene, int y, int x)
{

}

void TileObject::afterNight(GameWorld &world, Scene &scene)
{

}

void TileObject::tick(Scene &scene)
{

}

std::pair<int, int> TileObject::getPosition() const
{
    return {positionX, positionY};
}

bool TileObject::ableToInteract() const
{
    return false;
}
