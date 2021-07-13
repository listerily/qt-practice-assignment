//
// Created by listerily on 2021/7/13.
//

#ifndef STARDEW_VALLEY_LITE_PINETREEOBJECT_H
#define STARDEW_VALLEY_LITE_PINETREEOBJECT_H

#include "src/game/object/TileObject.h"

class PineTreeObject : public TileObject
{
public:
    PineTreeObject(int x, int y);

    void playerInteract(Player &player, ItemInstance *item) override;

    bool walkable(int i, int i1) const override;
};

#endif //STARDEW_VALLEY_LITE_PINETREEOBJECT_H
