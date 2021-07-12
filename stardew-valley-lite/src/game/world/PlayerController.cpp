//
// Created by listerily on 2021/7/12.
//

#include "PlayerController.h"
#include "GameWorld.h"
#include "../entity/Player.h"

PlayerController::PlayerController(GameWorld & world) : world(world)
{

}

void PlayerController::keyUp()
{
    world.getPlayer().move(0.0, -0.12);
}

void PlayerController::keyDown()
{
    world.getPlayer().move(0.0, 0.12);
}

void PlayerController::keyLeft()
{
    world.getPlayer().move(-0.12, 0.0);
}

void PlayerController::keyRight()
{
    world.getPlayer().move(0.12, 0.0);
}
