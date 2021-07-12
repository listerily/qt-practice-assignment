//
// Created by listerily on 2021/7/12.
//

#ifndef STARDEW_VALLEY_LITE_WATEROBJECT_H
#define STARDEW_VALLEY_LITE_WATEROBJECT_H

#include "../TileObject.h"

class WaterObject : public TileObject
{
public:
    WaterObject(int, int);

    bool walkable(int, int) const override;
};


#endif //STARDEW_VALLEY_LITE_WATEROBJECT_H
