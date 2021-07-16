//
// Created by listerily on 2021/7/13.
//

#include "FlowerPot.h"

#include "../../inventory/Inventory.h"
#include "../../action/PickupAction.h"

FlowerPot::FlowerPot(int x, int y, int aux) : TileObject("flower_pot", x, y)
{
    type = aux;
    regenerateTiles();
}

bool FlowerPot::ableToInteract() const
{
    return true;
}

std::unique_ptr<Action>
FlowerPot::interact(GameWorld &world, ItemInstance *instance, Player &player, Scene &scene, int x, int y)
{
    TileObject::interact(world, instance, player, scene, x, y);

    if (type == 1 && instance && instance->itemMatches(ItemInstance("weeds")))
    {
        instance->reduce(1);
        type = 0;
        regenerateTiles();
    } else if (type == 0)
    {
        type = 1;
        regenerateTiles();
        return std::make_unique<PickupAction>(*ItemInstance("weeds").getItem());
    }
    return nullptr;
}

void FlowerPot::regenerateTiles()
{
    tiles = {
            Tile{{type == 0 ? ":/svl/textures/tiles/0_23_43.png" : ":/svl/textures/tiles/0_23_44.png"},
                 Tile::WalkableType::DISABLE, 0, 0, Tile::DisplayPriority::ON_GROUND}
    };
}
