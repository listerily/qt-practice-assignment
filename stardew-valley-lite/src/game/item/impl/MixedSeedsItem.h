//
// Created by listerily on 2021/7/16.
//

#ifndef STARDEW_VALLEY_LITE_MIXEDSEEDSITEM_H
#define STARDEW_VALLEY_LITE_MIXEDSEEDSITEM_H

#include "../Item.h"

class MixedSeedItem : public Item
{
public:
    MixedSeedItem();

    const std::string &getTexture() const override;

    void onInteract(Player &, ItemInstance &, TileObject &) const override;
};


#endif //STARDEW_VALLEY_LITE_MIXEDSEEDSITEM_H
