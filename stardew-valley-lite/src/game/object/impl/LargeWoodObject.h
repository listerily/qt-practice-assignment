//
// Created by listerily on 2021/7/14.
//

#ifndef STARDEW_VALLEY_LITE_LARGEWOODOBJECT_H
#define STARDEW_VALLEY_LITE_LARGEWOODOBJECT_H

#include "../TileObject.h"

class LargeWoodObject : public TileObject
{
private:
    int life;
public:
    LargeWoodObject(int, int, int);

    bool ableToInteract() const override;

    std::unique_ptr<Action>
    interact(GameWorld &world, ItemInstance *instance, Player &player, Scene &scene, int x, int y) override;
};


#endif //STARDEW_VALLEY_LITE_LARGEWOODOBJECT_H
