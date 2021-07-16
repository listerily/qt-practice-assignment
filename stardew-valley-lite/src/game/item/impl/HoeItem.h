//
// Created by listerily on 2021/7/16.
//

#ifndef STARDEW_VALLEY_LITE_HOEITEM_H
#define STARDEW_VALLEY_LITE_HOEITEM_H

#include "../Item.h"

class HoeItem : public Item
{
public:
    HoeItem();

    const std::string &getTexture() const override;
};


#endif //STARDEW_VALLEY_LITE_HOEITEM_H
