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

std::unique_ptr<Action>
WeedsObject::interact(GameWorld &world, ItemInstance *item, Player &player, Scene &scene, int y, int x)
{
    TileObject::interact(world, item, player, scene, 0, 0);

    player.getInventory().addItemInstance(ItemInstance("weeds", 1));
    scene.removeObject(this);
    return nullptr;
}

bool WeedsObject::ableToInteract() const
{
    return true;
}
