//
// Created by listerily on 2021/7/16.
//

#ifndef STARDEW_VALLEY_LITE_AXEITEM_H
#define STARDEW_VALLEY_LITE_AXEITEM_H

#include "../Item.h"

class AxeItem : public Item
{
public:
    AxeItem();

    const std::string &getTexture() const override;
};


#endif //STARDEW_VALLEY_LITE_AXEITEM_H
