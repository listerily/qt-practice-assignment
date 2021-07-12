//
// Created by listerily on 2021/7/5.
//

#include "Entity.h"

Entity::Entity(GameWorld & gameWorld, GameDimension & dimension) : world(gameWorld), dimension(&dimension)
{
    x = y = 0.0;
    ax = ay = 0.0;
    vx = vy = 0.0;
    health = 0x7fffffff;
}

Entity::~Entity()
= default;

void Entity::tick()
{

}

void Entity::move(double deltaX, double deltaY)
{
    x += deltaX;
    y += deltaY;
}

void Entity::moveTo(double _x, double _y)
{
    x = _x;
    y = _y;
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

std::pair<double, double> Entity::getPosition() const
{
    return {x, y};
}
