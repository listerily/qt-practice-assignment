//
// Created by listerily on 2021/7/14.
//

#ifndef STARDEW_VALLEY_LITE_BORDEROBJECT_H
#define STARDEW_VALLEY_LITE_BORDEROBJECT_H

#include "../TileObject.h"

class BorderObject : public TileObject
{
public:
    BorderObject(int, int, int);

    bool ableToInteract() const override;
};


#endif //STARDEW_VALLEY_LITE_BORDEROBJECT_H
