//
// Created by listerily on 2021/7/6.
//

#ifndef STARDEW_VALLEY_LITE_TILEOBJECT_H
#define STARDEW_VALLEY_LITE_TILEOBJECT_H


#include <list>
#include <string>
#include <memory>
#include <src/game/inventory/ItemInstance.h>
#include <src/game/world/Scene.h>
#include <src/game/world/GameWorld.h>

#include "Tile.h"
#include "../action/Action.h"

class Item;
class Player;
class Tile;
class Scene;
class GameWorld;
class Action;
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
    virtual std::unique_ptr<Action>
    interact(GameWorld &world, ItemInstance *instance, Player &player, Scene &scene, int y, int x);
    virtual bool ableToInteract() const;
    virtual void afterNight(GameWorld &world, Scene &scene);
    virtual void tick(Scene &scene);
    virtual std::pair<int, int> getPosition() const;
};


#endif //STARDEW_VALLEY_LITE_TILEOBJECT_H
