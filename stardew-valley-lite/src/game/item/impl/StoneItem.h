//
// Created by listerily on 2021/7/13.
//

#ifndef STARDEW_VALLEY_LITE_STONEITEM_H
#define STARDEW_VALLEY_LITE_STONEITEM_H

#include "../Item.h"

class StoneItem : public Item
{
public:
    StoneItem();

    const std::string &getTexture() const override;
};


#endif //STARDEW_VALLEY_LITE_STONEITEM_H
