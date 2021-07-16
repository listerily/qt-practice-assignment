//
// Created by listerily on 2021/7/15.
//

#ifndef STARDEW_VALLEY_LITE_BEDOBJECT_H
#define STARDEW_VALLEY_LITE_BEDOBJECT_H

#include "../TileObject.h"

class BedObject : public TileObject
{
public:
    BedObject(int, int);

    bool ableToInteract() const override;

    std::unique_ptr<Action>
    interact(GameWorld &world, ItemInstance *instance, Player &player, Scene &scene, int x, int y) override;
};


#endif //STARDEW_VALLEY_LITE_BEDOBJECT_H
