//
// Created by listerily on 2021/7/12.
//

#include "PlayerController.h"
#include "GameWorld.h"
#include "../entity/Player.h"

PlayerController::PlayerController(GameWorld & world) : world(world)
{

}

void PlayerController::moveUp()
{
    world.getPlayer().walk(0.0, -0.12);
}

void PlayerController::moveDown()
{
    world.getPlayer().walk(0.0, 0.12);
}

void PlayerController::moveLeft()
{
    world.getPlayer().walk(-0.12, 0.0);
}

void PlayerController::moveRight()
{
    world.getPlayer().walk(0.12, 0.0);
}

void PlayerController::selectInventorySlot(int)
{

}
