//
// Created by listerily on 2021/7/15.
//

#include "PlayerStatus.h"

PlayerStatus::PlayerStatus()
{
    current = NONE;
    time = 0;
    item = nullptr;
    facing = Player::Facing::DOWN;
}

void PlayerStatus::setPickup(const Item * i)
{
    current = PICKUP;
    time = getDuration();
    item = i;
}

void PlayerStatus::setEating(const Item * i)
{
    current = EATING;
    time = getDuration();
    item = i;
}

void PlayerStatus::setUsingTool(const Item * i, Player::Facing f)
{
    current = USE_TOOL;
    time = getDuration();
    item = i;
    facing = f;
}

void PlayerStatus::tick()
{
    if(time != 0 && --time == 0)
        current = NONE;
}

bool PlayerStatus::isInStatus() const
{
    return current != NONE;
}

int PlayerStatus::getProgress() const
{
    return getDuration() - time;
}

int PlayerStatus::getDuration() const
{
    switch (current)
    {
        case PICKUP:
            return 30;
        case EATING:
            return 40;
        case USE_TOOL:
            return 50;
        default:
            return 0;
    }
}

PlayerStatus::Status PlayerStatus::getStatus() const
{
    return current;
}

const Item *PlayerStatus::getStatusItem() const
{
    return item;
}

Player::Facing PlayerStatus::getStatusFacing() const
{
    return facing;
}
