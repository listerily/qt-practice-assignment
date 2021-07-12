//
// Created by listerily on 2021/7/12.
//

#ifndef STARDEW_VALLEY_LITE_OAKTREEOBJECT_H
#define STARDEW_VALLEY_LITE_OAKTREEOBJECT_H

#include "../TileObject.h"

class OakTreeObject : public TileObject
{
public:
    OakTreeObject(int x, int y);

    void playerInteract(Player &player, Item &item, int x, int y) override;

    bool walkable(int i, int i1) const override;
};


#endif //STARDEW_VALLEY_LITE_OAKTREEOBJECT_H
