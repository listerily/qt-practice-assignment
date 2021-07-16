//
// Created by listerily on 2021/7/15.
//

#ifndef STARDEW_VALLEY_LITE_STRAWBERRYITEM_H
#define STARDEW_VALLEY_LITE_STRAWBERRYITEM_H

#include "../Item.h"

class StrawberryItem : public Item
{
public:
    StrawberryItem();

    const std::string &getTexture() const override;
};


#endif //STARDEW_VALLEY_LITE_STRAWBERRYITEM_H
