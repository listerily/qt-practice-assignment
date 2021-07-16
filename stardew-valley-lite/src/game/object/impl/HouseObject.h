//
// Created by listerily on 2021/7/14.
//

#ifndef STARDEW_VALLEY_LITE_HOUSEOBJECT_H
#define STARDEW_VALLEY_LITE_HOUSEOBJECT_H

#include <src/game/world/Scene.h>
#include <src/game/world/GameWorld.h>
#include "../TileObject.h"

class HouseObject : public TileObject
{
public:
    HouseObject(int, int);

    std::unique_ptr<Action> interact(GameWorld &world, ItemInstance *instance, Player &player, Scene &scene, int y, int x) override;

    bool ableToInteract() const override;
};


#endif //STARDEW_VALLEY_LITE_HOUSEOBJECT_H
