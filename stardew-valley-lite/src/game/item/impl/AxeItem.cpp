//
// Created by listerily on 2021/7/16.
//

#include "AxeItem.h"

AxeItem::AxeItem() : Item("axe")
{

}

const std::string &AxeItem::getTexture() const
{
    const static std::string val = ":/svl/textures/tools/5_5_10.png";
    return val;
}
