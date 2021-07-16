//
// Created by listerily on 2021/7/13.
//

#ifndef STARDEW_VALLEY_LITE_WEEDSOBJECT_H
#define STARDEW_VALLEY_LITE_WEEDSOBJECT_H

#include <src/game/world/Scene.h>
#include <src/game/world/GameWorld.h>
#include "../TileObject.h"

class WeedsObject : public TileObject
{
public:
    WeedsObject(int, int, int);

    std::unique_ptr<Action>
    interact(GameWorld &world, ItemInstance *instance, Player &player, Scene &scene, int y, int x) override;

    bool ableToInteract() const override;
};


#endif //STARDEW_VALLEY_LITE_WEEDSOBJECT_H
