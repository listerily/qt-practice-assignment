//
// Created by listerily on 2021/7/13.
//

#ifndef STARDEW_VALLEY_LITE_STONEOBJECT_H
#define STARDEW_VALLEY_LITE_STONEOBJECT_H

#include "../TileObject.h"

class StoneObject : public TileObject
{
public:
    StoneObject(int, int);

    bool walkable(int, int) const override;
    void playerInteract(Player &, ItemInstance &) override;
};


#endif //STARDEW_VALLEY_LITE_STONEOBJECT_H
