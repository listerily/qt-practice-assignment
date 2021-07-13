//
// Created by listerily on 2021/7/13.
//

#include "WoodItem.h"

WoodItem::WoodItem() : Item("wood")
{

}

const std::string &WoodItem::getTexture() const
{
    static const std::string val = ":/svl/textures/items/4_4_16.png";
    return val;
}
