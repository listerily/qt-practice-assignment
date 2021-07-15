//
// Created by listerily on 2021/7/13.
//

#include "FruitsBarrel.h"

#include "../../inventory/Inventory.h"

FruitsBarrel::FruitsBarrel(int x, int y) : TileObject("fruits_barrel", x ,y)
{
    tiles = {
            Tile{{":/svl/textures/tiles/0_17_4.png"}, Tile::WalkableType::DISABLE, 0, 0, Tile::DisplayPriority::ON_GROUND}
    };
}

bool FruitsBarrel::ableToInteract() const
{
    return true;
}

void FruitsBarrel::playerInteract(GameWorld &world, ItemInstance *instance, Player &player, Scene &scene, int y, int x)
{
    TileObject::playerInteract(world, instance, player, scene, y, x);

    player.getInventory().addItemInstance(ItemInstance("strawberry", 1));
}
