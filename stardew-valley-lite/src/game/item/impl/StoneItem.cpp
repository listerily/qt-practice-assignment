//
// Created by listerily on 2021/7/13.
//

#include "StoneItem.h"

StoneItem::StoneItem() : Item("stone")
{

}

const std::string &StoneItem::getTexture() const
{
    const static std::string val = ":/svl/textures/items/4_6_16.png";
    return val;
}
