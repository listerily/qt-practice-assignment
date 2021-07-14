//
// Created by listerily on 2021/7/13.
//

#include "WeedsObject.h"

#include "../../entity/Player.h"
#include "../../inventory/Inventory.h"
#include "../../inventory/ItemInstance.h"

WeedsObject::WeedsObject(int x, int y, int type) : TileObject("weeds", x, y)
{
    std::vector<std::string> textures = {":/svl/textures/items/4_2_28.png", ":/svl/textures/items/4_3_28.png", ":/svl/textures/items/4_4_28.png", ":/svl/textures/items/4_5_28.png"};
    tiles = {
            Tile{{textures[type]}, Tile::WalkableType::DISABLE, 0, 0, Tile::DisplayPriority::ON_GROUND}
    };
}

void WeedsObject::playerInteract(Player & player, ItemInstance *item)
{
    TileObject::playerInteract(player, item);

    player.getInventory().addItemInstance(ItemInstance("weeds", 1));
}

bool WeedsObject::ableToInteract() const
{
    return true;
}
