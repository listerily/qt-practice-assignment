//
// Created by listerily on 2021/7/13.
//

#ifndef STARDEW_VALLEY_LITE_WOODITEM_H
#define STARDEW_VALLEY_LITE_WOODITEM_H

#include "../Item.h"

class WoodItem : public Item
{
public:
    WoodItem();

    const std::string & getTexture() const override;
};


#endif //STARDEW_VALLEY_LITE_WOODITEM_H
