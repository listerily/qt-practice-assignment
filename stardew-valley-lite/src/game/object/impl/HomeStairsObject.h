//
// Created by listerily on 2021/7/15.
//

#ifndef STARDEW_VALLEY_LITE_HOMESTAIRSOBJECT_H
#define STARDEW_VALLEY_LITE_HOMESTAIRSOBJECT_H

#include <src/game/world/Scene.h>
#include <src/game/world/GameWorld.h>
#include "../TileObject.h"

class HomeStairsObject : public TileObject
{
public:
    HomeStairsObject(int, int);

    bool ableToInteract() const override;
    std::unique_ptr<Action> interact(GameWorld &world, ItemInstance *instance, Player &player, Scene &scene, int y, int x) override;
};


#endif //STARDEW_VALLEY_LITE_HOMESTAIRSOBJECT_H
