//
// Created by listerily on 2021/7/16.
//

#ifndef STARDEW_VALLEY_LITE_PARSNIPITEM_H
#define STARDEW_VALLEY_LITE_PARSNIPITEM_H

#include "../Item.h"

class ParsnipItem : public Item
{
public:
    ParsnipItem();

    const std::string &getTexture() const override;
};


#endif //STARDEW_VALLEY_LITE_PARSNIPITEM_H
