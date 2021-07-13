//
// Created by listerily on 2021/7/13.
//

#include "WeedsObject.h"

WeedsObject::WeedsObject(int x, int y, int type) : TileObject("weeds", x, y)
{
    std::vector<std::string> textures = {":/svl/textures/items/4_2_28.png", ":/svl/textures/items/4_3_28.png", ":/svl/textures/items/4_4_28.png", ":/svl/textures/items/4_5_28.png"};
    tiles = {
            Tile{{textures[type]}, false, 0, 0, Tile::DisplayPriority::ON_GROUND}
    };
}

void WeedsObject::playerInteract(Player & player, ItemInstance *item)
{
    TileObject::playerInteract(player, item);
}

bool WeedsObject::walkable(int, int) const
{
    return false;
}
