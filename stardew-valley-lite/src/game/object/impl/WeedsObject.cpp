//
// Created by listerily on 2021/7/13.
//

#include "WeedsObject.h"

#include "../../entity/Player.h"
#include "../../inventory/Inventory.h"
#include "../../inventory/ItemInstance.h"
#include "../../action/SmashAndGetAction.h"

WeedsObject::WeedsObject(int x, int y, int type) : TileObject("weeds", x, y), type(type)
{
    std::vector<std::string> textures = {":/svl/textures/items/4_2_28.png", ":/svl/textures/items/4_3_28.png",
                                         ":/svl/textures/items/4_4_28.png", ":/svl/textures/items/4_5_28.png"};
    tiles = {
            Tile{{textures[type]}, Tile::WalkableType::DISABLE, 0, 0, Tile::DisplayPriority::ON_GROUND}
    };
}

std::unique_ptr<Action>
WeedsObject::interact(GameWorld &world, ItemInstance *item, Player &player, Scene &scene, int x, int y)
{
    if (item && item->itemMatches(ItemInstance("hoe")))
        return std::make_unique<SmashAndGetAction>(*(item->getItem()), type <= 1 ? ItemInstance("weeds", 1) :
                                                                       ItemInstance("mixed_seeds", 1), *this, true);
    return TileObject::interact(world, item, player, scene, x, y);
}

bool WeedsObject::ableToInteract() const
{
    return true;
}
