//
// Created by listerily on 2021/7/12.
//

#ifndef STARDEW_VALLEY_LITE_OAKTREEOBJECT_H
#define STARDEW_VALLEY_LITE_OAKTREEOBJECT_H

#include "src/game/object/TileObject.h"

class OakTreeObject : public TileObject
{
public:
    OakTreeObject(int x, int y);

    std::unique_ptr<Action> interact(GameWorld &world, ItemInstance *item, Player &player, Scene &scene, int y, int x) override;
};


#endif //STARDEW_VALLEY_LITE_OAKTREEOBJECT_H
