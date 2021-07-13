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

void PlayerController::walkUp(double speed)
{
    walk(0.0, -speed);
}

void PlayerController::walkDown(double speed)
{
    walk(0.0, speed);
}

void PlayerController::walkLeft(double speed)
{
    walk(-speed, 0.0);
}

void PlayerController::walkRight(double speed)
{
    walk(speed, 0.0);
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

void PlayerController::walk(double dx, double dy)
{
    auto& player = world.getPlayer();
    auto const& position = player.getPosition();
    player.turn(dx, dy);
    if(player.isWalkable(position.first + dx, position.second + dy))
    {
        player.move(dx, dy);
        return;
    }

    //Moving Optimization
    for(auto const& facingPosition : player.getFacingPositions())
    {
        if(player.isTileWalkable(facingPosition.first, facingPosition.second))
        {
            double targetX = facingPosition.first + 0.5;
            double targetY = facingPosition.second + 0.5;
            if(targetX > position.first && player.isWalkable(position.first + 0.05, position.second))
                player.move(0.05, 0.0);
            if(targetX < position.first && player.isWalkable(position.first - 0.05, position.second))
                player.move(-0.05, 0.0);
            if(targetY > position.second && player.isWalkable(position.first, position.second + 0.05))
                player.move(0.0, 0.05);
            if(targetY < position.second && player.isWalkable(position.first, position.second - 0.05))
                player.move(0.0, -0.05);
            break;
        }
    }
}

void PlayerController::walk(bool up, bool down, bool left, bool right)
{
    const double speedNormal = 0.1;
    const double speedDiagonal = 0.07;

    bool towardsRight = true;
    bool towardsLeft = true;
    bool towardsUp = true;
    bool towardsDown = true;

    if(up && down)
        towardsDown = towardsUp = false;
    if(left && right)
        towardsLeft = towardsRight = false;

    towardsUp = towardsUp && up;
    towardsDown = towardsDown && down;
    towardsLeft = towardsLeft && left;
    towardsRight = towardsRight && right;

    if(towardsRight && towardsUp)
        walkUp(speedDiagonal), walkRight(speedDiagonal);
    else if(towardsLeft && towardsUp)
        walkUp(speedDiagonal), walkLeft(speedDiagonal);
    else if(towardsRight && towardsDown)
        walkDown(speedDiagonal), walkRight(speedDiagonal);
    else if(towardsLeft && towardsDown)
        walkDown(speedDiagonal), walkLeft(speedDiagonal);
    else if(towardsUp)
        walkUp(speedNormal);
    else if(towardsDown)
        walkDown(speedNormal);
    else if(towardsLeft)
        walkLeft(speedNormal);
    else if(towardsRight)
        walkRight(speedNormal);
}
