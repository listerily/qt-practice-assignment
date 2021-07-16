//
// Created by listerily on 2021/7/16.
//

#include "HoeItem.h"

HoeItem::HoeItem() : Item("hoe")
{

}

const std::string &HoeItem::getTexture() const
{
    const static std::string val = ":/svl/textures/tools/5_5_2.png";
    return val;
}
