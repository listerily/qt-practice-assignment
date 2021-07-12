//
// Created by listerily on 2021/7/12.
//

#ifndef STARDEW_VALLEY_LITE_SMALLSTONE_H
#define STARDEW_VALLEY_LITE_SMALLSTONE_H

#include "../TileObject.h"

class SmallStone : public TileObject
{
public:
    SmallStone(int, int);

    bool walkable(int, int) const override;
};


#endif //STARDEW_VALLEY_LITE_SMALLSTONE_H
