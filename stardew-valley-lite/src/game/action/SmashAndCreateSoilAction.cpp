//
// Created by listerily on 2021/7/16.
//

#include "SmashAndCreateSoilAction.h"

#include "../world/Scene.h"
#include "../object/factory/TileObjectFactory.h"

SmashAndCreateSoilAction::SmashAndCreateSoilAction(const Item &item, int x, int y) : SmashAction(item)
{
    this->x = x;
    this->y = y;
}

void SmashAndCreateSoilAction::onActionEnd(GameWorld &w, Scene &s, Player &p)
{
    SmashAction::onActionEnd(w, s, p);

    s.addNewObject(TileObjectFactory::generateTileObjectByIdAt("hoe_soil", x, y));
}
