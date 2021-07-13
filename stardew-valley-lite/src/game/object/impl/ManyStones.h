//
// Created by listerily on 2021/7/12.
//

#ifndef STARDEW_VALLEY_LITE_MANYSTONES_H
#define STARDEW_VALLEY_LITE_MANYSTONES_H

#include "src/game/object/TileObject.h"

class ManyStones : public TileObject
{
public:
    ManyStones(int, int);

    bool walkable(int, int) const override;
};


#endif //STARDEW_VALLEY_LITE_MANYSTONES_H
