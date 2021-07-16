//
// Created by listerily on 2021/7/16.
//

#include "ParsnipItem.h"

ParsnipItem::ParsnipItem() : Item("parsnip")
{

}

const std::string &ParsnipItem::getTexture() const
{
    static const std::string val = ":/svl/textures/items/4_0_1.png";
    return val;
}
