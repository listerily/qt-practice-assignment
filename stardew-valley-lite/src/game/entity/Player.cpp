//
// Created by listerily on 2021/7/5.
//

#include "Player.h"

#include <cmath>

#include "../world/TileSheet.h"
#include "../world/GameDimension.h"

std::string Player::getID() const
{
    return "player";
}

Player::Player(GameWorld & world, GameDimension & dimension) : Entity(world, dimension)
{
    facing = Facing::DOWN;
    movingVariant = 0;
}

Player::Facing Player::getFacing() const
{
    return facing;
}

bool Player::isMoving() const
{
    return movingVariant > 0;
}

void Player::move(double x, double y)
{
    Entity::move(x, y);
    renewFacing(x, y);
    movingVariant = 5;
}

void Player::tick()
{
    Entity::tick();
    if(movingVariant > 0)
        --movingVariant;
}

void Player::walk(double dx, double dy)
{
    renewFacing(dx, dy);
    if(isWalkable(x + dx, y + dy))
        move(dx, dy);
}

bool Player::isWalkable(double x, double y) const
{
    const double DETECTION_RADIUS = 0.25;
    return isTileWalkable(floor(x - DETECTION_RADIUS), floor(y - DETECTION_RADIUS)) &&
            isTileWalkable(floor(x + DETECTION_RADIUS), floor(y + DETECTION_RADIUS)) &&
            isTileWalkable(floor(x - DETECTION_RADIUS), floor(y + DETECTION_RADIUS)) &&
            isTileWalkable(floor(x + DETECTION_RADIUS), floor(y - DETECTION_RADIUS));
}

bool Player::isTileWalkable(int x, int y) const
{
    const auto& tileObjects = dimension->getTileSheet().getTileObjectsAt(x, y);
    for(const auto& tileObject : tileObjects)
    {
        if(!tileObject->walkable(x, y))
            return false;
    }
    return true;
}

void Player::renewFacing(double x, double y)
{
    if(x > 0.0 && y == 0.0)
        facing = Facing::RIGHT;
    if(x < 0.0 && y == 0.0)
        facing = Facing::LEFT;
    if(x == 0.0 && y > 0.0)
        facing = Facing::DOWN;
    if(x == 0.0 && y < 0.0)
        facing = Facing::UP;
}
