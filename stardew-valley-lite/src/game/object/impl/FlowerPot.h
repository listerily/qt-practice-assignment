//
// Created by listerily on 2021/7/13.
//

#ifndef STARDEW_VALLEY_LITE_FLOWERPOT_H
#define STARDEW_VALLEY_LITE_FLOWERPOT_H

#include "../TileObject.h"

class FlowerPot : public TileObject
{
private:
    int type;
public:
    FlowerPot(int, int, int);

    bool ableToInteract() const override;

    std::unique_ptr<Action>
    interact(GameWorld &world, ItemInstance *instance, Player &player, Scene &scene, int x, int y) override;

private:
    void regenerateTiles();
};


#endif //STARDEW_VALLEY_LITE_FLOWERPOT_H
