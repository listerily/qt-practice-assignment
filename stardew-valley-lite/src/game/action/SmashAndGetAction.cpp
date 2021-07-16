//
// Created by listerily on 2021/7/16.
//

#include "SmashAndGetAction.h"

#include "../entity/Player.h"
#include "../inventory/Inventory.h"
#include "../world/Scene.h"

SmashAndGetAction::SmashAndGetAction(const Item &item, const ItemInstance &instance, TileObject &tile, bool remove)
        : SmashAction(item),
          harvest(instance),
          tileObject(tile),
          shouldRemoveObject(remove)
{

}

void SmashAndGetAction::onActionEnd(GameWorld &w, Scene &s, Player &p)
{
    SmashAction::onActionEnd(w, s, p);

    if (!harvest.empty())
        p.getInventory().addItemInstance(harvest);
    if (shouldRemoveObject)
        s.removeObject(&tileObject);
}

