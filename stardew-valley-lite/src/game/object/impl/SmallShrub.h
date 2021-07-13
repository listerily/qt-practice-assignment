//
// Created by listerily on 2021/7/12.
//

#ifndef STARDEW_VALLEY_LITE_SMALLSHRUB_H
#define STARDEW_VALLEY_LITE_SMALLSHRUB_H

#include "src/game/object/TileObject.h"

class SmallShrub : public TileObject
{
public:
    SmallShrub(int x, int y);

    void playerInteract(Player &player, Item &item, int x, int y) override;

    bool walkable(int i, int i1) const override;
};


#endif //STARDEW_VALLEY_LITE_SMALLSHRUB_H
