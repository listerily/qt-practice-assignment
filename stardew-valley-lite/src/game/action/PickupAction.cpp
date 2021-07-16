//
// Created by listerily on 2021/7/15.
//

#include "PickupAction.h"

#include "../entity/Player.h"
#include "../inventory/Inventory.h"

int PickupAction::getDuration() const
{
    return 15;
}

PickupAction::PickupAction(const Item &i) : item(i)
{

}

void PickupAction::onActionEnd(GameWorld &w, Scene &s, Player &p)
{
    Action::onActionEnd(w, s, p);

    p.getInventory().addItemInstance(ItemInstance(&item, 1));
}

const Item &PickupAction::getItem() const
{
    return item;
}
