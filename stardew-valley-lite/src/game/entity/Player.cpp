//
// Created by listerily on 2021/7/5.
//

#include "Player.h"

std::string Player::getID() const
{
    return "player";
}

Player::Player(GameWorld & world, GameDimension & dimension) : Entity(world, dimension)
{

}