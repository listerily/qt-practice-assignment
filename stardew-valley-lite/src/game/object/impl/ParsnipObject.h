//
// Created by listerily on 2021/7/16.
//

#ifndef STARDEW_VALLEY_LITE_PARSNIPOBJECT_H
#define STARDEW_VALLEY_LITE_PARSNIPOBJECT_H

#include "../TileObject.h"

class ParsnipObject : public TileObject
{
private:
    int stage;
public:
    ParsnipObject(int, int);

    void afterNight(GameWorld &world, Scene &scene) override;

    std::unique_ptr<Action>
    interact(GameWorld &world, ItemInstance *instance, Player &player, Scene &scene, int x, int y) override;

private:
    void updateTiles();
};


#endif //STARDEW_VALLEY_LITE_PARSNIPOBJECT_H
