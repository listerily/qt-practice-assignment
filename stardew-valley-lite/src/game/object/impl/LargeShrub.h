//
// Created by listerily on 2021/7/12.
//

#ifndef STARDEW_VALLEY_LITE_LARGESHRUB_H
#define STARDEW_VALLEY_LITE_LARGESHRUB_H

#include <src/game/world/Scene.h>
#include <src/game/world/GameWorld.h>
#include "src/game/object/TileObject.h"

class LargeShrub : public TileObject
{
public:
    LargeShrub(int x, int y);

    std::unique_ptr<Action>
    interact(GameWorld &world, ItemInstance *item, Player &player, Scene &scene, int x, int y) override;
};


#endif //STARDEW_VALLEY_LITE_LARGESHRUB_H
