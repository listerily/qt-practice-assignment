//
// Created by listerily on 2021/7/12.
//

#include "PlayerController.h"
#include "GameWorld.h"
#include "../entity/Player.h"
#include "../inventory/Inventory.h"

PlayerController::PlayerController(GameWorld & world) : world(world)
{

}

void PlayerController::walkUp()
{
    world.getPlayer().walk(0.0, -0.12);
}

void PlayerController::walkDown()
{
    world.getPlayer().walk(0.0, 0.12);
}

void PlayerController::walkLeft()
{
    world.getPlayer().walk(-0.12, 0.0);
}

void PlayerController::walkRight()
{
    world.getPlayer().walk(0.12, 0.0);
}

void PlayerController::selectInventorySlot(int slot)
{
    world.getPlayer().getInventory().setSelectedSlot(slot);
}

Inventory &PlayerController::getInventory()
{
    return world.getPlayer().getInventory();
}

const Inventory &PlayerController::getInventory() const
{
    return world.getPlayer().getInventory();
}
