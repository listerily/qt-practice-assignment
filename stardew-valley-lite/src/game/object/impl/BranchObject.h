//
// Created by listerily on 2021/7/13.
//

#ifndef STARDEW_VALLEY_LITE_BRANCHOBJECT_H
#define STARDEW_VALLEY_LITE_BRANCHOBJECT_H

#include "../TileObject.h"

class BranchObject : public TileObject
{
public:
    BranchObject(int, int, int);

    void playerInteract(Player &, ItemInstance *) override;
};


#endif //STARDEW_VALLEY_LITE_BRANCHOBJECT_H
