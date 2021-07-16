//
// Created by listerily on 2021/7/15.
//

#ifndef STARDEW_VALLEY_LITE_PICKUPACTION_H
#define STARDEW_VALLEY_LITE_PICKUPACTION_H

#include "Action.h"

class Item;
class PickupAction : public Action
{
private:
    const Item& item;
public:
    explicit PickupAction(const Item&);

    int getDuration() const override;
    void onActionEnd(GameWorld &w, Scene &s, Player &p) override;
    const Item& getItem() const;
};


#endif //STARDEW_VALLEY_LITE_PICKUPACTION_H
