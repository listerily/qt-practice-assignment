//
// Created by listerily on 2021/7/13.
//

#ifndef STARDEW_VALLEY_LITE_BRANCHOBJECT_H
#define STARDEW_VALLEY_LITE_BRANCHOBJECT_H

#include <src/game/world/Scene.h>
#include <src/game/world/GameWorld.h>
#include "../TileObject.h"

class BranchObject : public TileObject
{
public:
    BranchObject(int, int, int);

    bool ableToInteract() const override;

    std::unique_ptr<Action>
    interact(GameWorld &world, ItemInstance *instance, Player &player, Scene &scene, int x, int y) override;
};


#endif //STARDEW_VALLEY_LITE_BRANCHOBJECT_H
