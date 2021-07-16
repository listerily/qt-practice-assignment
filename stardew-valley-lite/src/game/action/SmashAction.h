//
// Created by listerily on 2021/7/16.
//

#ifndef STARDEW_VALLEY_LITE_SMASHACTION_H
#define STARDEW_VALLEY_LITE_SMASHACTION_H

#include "Action.h"

class Item;

class TileObject;

class SmashAction : public Action
{
private:
    const Item &tool;
    const Item &harvest;
    TileObject &tileObject;
public:
    SmashAction(const Item &, const Item &, TileObject &);

    int getDuration() const override;

    void onActionEnd(GameWorld &w, Scene &s, Player &p) override;

    const Item &getToolItem() const;
};


#endif //STARDEW_VALLEY_LITE_SMASHACTION_H
