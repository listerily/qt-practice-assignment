//
// Created by listerily on 2021/7/13.
//

#ifndef STARDEW_VALLEY_LITE_WEEDSITEM_H
#define STARDEW_VALLEY_LITE_WEEDSITEM_H

#include "../Item.h"

class WeedsItem : public Item
{
public:
    WeedsItem();

    const std::string & getTexture() const override;
};


#endif //STARDEW_VALLEY_LITE_WEEDSITEM_H
