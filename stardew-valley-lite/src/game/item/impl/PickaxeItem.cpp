//
// Created by listerily on 2021/7/16.
//

#include "PickaxeItem.h"

PickaxeItem::PickaxeItem() : Item("pickaxe")
{

}

const std::string &PickaxeItem::getTexture() const
{
    const static std::string val = ":/svl/textures/tools/5_5_6.png";
    return val;
}
