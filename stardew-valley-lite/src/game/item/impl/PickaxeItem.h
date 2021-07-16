//
// Created by listerily on 2021/7/16.
//

#ifndef STARDEW_VALLEY_LITE_PICKAXEITEM_H
#define STARDEW_VALLEY_LITE_PICKAXEITEM_H

#include "../Item.h"

class PickaxeItem : public Item
{
public:
    PickaxeItem();

    const std::string &getTexture() const override;
};


#endif //STARDEW_VALLEY_LITE_PICKAXEITEM_H
