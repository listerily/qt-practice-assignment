//
// Created by listerily on 2021/7/15.
//

#ifndef STARDEW_VALLEY_LITE_HOUSEBACKGROUNDOBJECT_H
#define STARDEW_VALLEY_LITE_HOUSEBACKGROUNDOBJECT_H

#include "../TileObject.h"

class HouseBackgroundObject : public TileObject
{
public:
    HouseBackgroundObject(int, int);

    bool ableToInteract() const override;
};


#endif //STARDEW_VALLEY_LITE_HOUSEBACKGROUNDOBJECT_H
