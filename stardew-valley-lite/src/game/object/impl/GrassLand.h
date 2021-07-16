//
// Created by listerily on 2021/7/6.
//

#ifndef STARDEW_VALLEY_LITE_GRASSLAND_H
#define STARDEW_VALLEY_LITE_GRASSLAND_H

#include "src/game/object/TileObject.h"

class GrassLand : public TileObject
{
private:
    bool hoeAble;
public:
    GrassLand(int x, int y, int aux);

    std::unique_ptr<Action>
    interact(GameWorld &world, ItemInstance *instance, Player &player, Scene &scene, int x, int y) override;
};


#endif //STARDEW_VALLEY_LITE_GRASSLAND_H
