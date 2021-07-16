//
// Created by listerily on 2021/7/16.
//

#include "SmashAction.h"

#include "../inventory/Inventory.h"
#include "../entity/Player.h"
#include "../world/Scene.h"

SmashAction::SmashAction(const Item &tool, const Item &harvest, TileObject &tileObject) : tool(tool), harvest(harvest),
                                                                                          tileObject(tileObject)
{

}

int SmashAction::getDuration() const
{
    return 10;
}

void SmashAction::onActionEnd(GameWorld &w, Scene &s, Player &p)
{
    Action::onActionEnd(w, s, p);

    p.getInventory().addItemInstance(ItemInstance(&harvest, 1));
    s.removeObject(&tileObject);
}

const Item &SmashAction::getToolItem() const
{
    return tool;
}
