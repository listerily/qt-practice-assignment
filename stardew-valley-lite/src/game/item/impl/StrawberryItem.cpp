//
// Created by listerily on 2021/7/15.
//

#include "StrawberryItem.h"

StrawberryItem::StrawberryItem() : Item("strawberry")
{

}

const std::string &StrawberryItem::getTexture() const
{
    static const std::string val = ":/svl/textures/items/4_16_16.png";
    return val;
}
