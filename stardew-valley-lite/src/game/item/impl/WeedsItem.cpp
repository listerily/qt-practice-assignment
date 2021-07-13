//
// Created by listerily on 2021/7/13.
//

#include "WeedsItem.h"

WeedsItem::WeedsItem() : Item("weeds")
{

}

const std::string &WeedsItem::getTexture() const
{
    static const std::string val = ":/svl/textures/items/4_3_32.png";
    return val;
}
