//
// Created by listerily on 2021/7/13.
//

#include "FruitsBarrel.h"

#include "../../inventory/Inventory.h"
#include "../../action/PickupAction.h"

FruitsBarrel::FruitsBarrel(int x, int y) : TileObject("fruits_barrel", x, y)
{
    tiles = {
            Tile{{":/svl/textures/tiles/0_17_4.png"}, Tile::WalkableType::DISABLE, 0, 0,
                 Tile::DisplayPriority::ON_GROUND}
    };
}

bool FruitsBarrel::ableToInteract() const
{
    return true;
}

std::unique_ptr<Action>
FruitsBarrel::interact(GameWorld &world, ItemInstance *instance, Player &player, Scene &scene, int x, int y)
{
    TileObject::interact(world, instance, player, scene, x, y);

    return std::make_unique<PickupAction>(*ItemInstance("strawberry").getItem());
}
