//
// Created by listerily on 2021/7/16.
//

#include "MixedSeedsItem.h"

MixedSeedItem::MixedSeedItem() : Item("mixed_seeds")
{

}

const std::string &MixedSeedItem::getTexture() const
{
    static const std::string val = ":/svl/textures/items/4_2_32.png";
    return val;
}

void MixedSeedItem::onInteract(Player &p, ItemInstance &instance, TileObject &tileObject) const
{
    return Item::onInteract(p, instance, tileObject);
}
