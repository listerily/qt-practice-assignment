//
// Created by listerily on 2021/7/13.
//

#ifndef STARDEW_VALLEY_LITE_FRUITSBARREL_H
#define STARDEW_VALLEY_LITE_FRUITSBARREL_H

#include "../TileObject.h"

class FruitsBarrel : public TileObject
{
public:
    FruitsBarrel(int, int);

    bool ableToInteract() const override;

    std::unique_ptr<Action>
    interact(GameWorld &world, ItemInstance *instance, Player &player, Scene &scene, int x, int y) override;
};


#endif //STARDEW_VALLEY_LITE_FRUITSBARREL_H
