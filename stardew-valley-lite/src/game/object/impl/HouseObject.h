//
// Created by listerily on 2021/7/14.
//

#ifndef STARDEW_VALLEY_LITE_HOUSEOBJECT_H
#define STARDEW_VALLEY_LITE_HOUSEOBJECT_H

#include "../TileObject.h"

class HouseObject : public TileObject
{
public:
    HouseObject(int, int);

    void playerInteract(Player &, ItemInstance *) override;

    bool ableToInteract() const override;
};


#endif //STARDEW_VALLEY_LITE_HOUSEOBJECT_H
