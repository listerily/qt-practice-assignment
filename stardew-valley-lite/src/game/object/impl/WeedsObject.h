//
// Created by listerily on 2021/7/13.
//

#ifndef STARDEW_VALLEY_LITE_WEEDSOBJECT_H
#define STARDEW_VALLEY_LITE_WEEDSOBJECT_H

#include "../TileObject.h"

class WeedsObject : public TileObject
{
public:
    WeedsObject(int, int, int);

    void playerInteract(Player &, ItemInstance &) override;
    bool walkable(int, int) const override;
};


#endif //STARDEW_VALLEY_LITE_WEEDSOBJECT_H
