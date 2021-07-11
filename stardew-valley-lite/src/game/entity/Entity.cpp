//
// Created by listerily on 2021/7/5.
//

#include "Entity.h"

Entity::Entity(GameWorld & gameWorld, GameDimension & dimension) : world(gameWorld), dimension(&dimension)
{
    x = y = 0.0;
}

Entity::~Entity()
= default;

void Entity::tick()
{

}

void Entity::move(double, double)
{
    //TODO: implement Entity methods.
}

void Entity::moveTo(double, double)
{

}

float Entity::getFriction() const
{
    return 0;
}

std::pair<double, double> Entity::getAcceleration() const
{
    return std::pair<double, double>();
}

std::pair<double, double> Entity::getVelocity() const
{
    return std::pair<double, double>();
}

void Entity::setDimension(GameDimension & newDimension)
{
    dimension = &newDimension;
}

int Entity::getHealth() const
{
    return health;
}

void Entity::hurt(int hp)
{
    health -= hp;
    if (health <= 0)
        onDeath();
}

void Entity::onDeath()
{

}
