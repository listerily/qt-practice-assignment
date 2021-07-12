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
    solveAcceleration();
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

float Entity::getFriction() const
{
    return 0.1;
}

std::pair<double, double> Entity::getAcceleration() const
{
    return {ax, ay};
}

std::pair<double, double> Entity::getVelocity() const
{
    return {vx, vy};
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

void Entity::applyAcceleration(double _ax, double _ay)
{
    ax += _ax;
    ay += _ay;
}

void Entity::solveAcceleration()
{
    vx += ax;
    vy += ay;
    ax = ay = 0.0;
    if(vx > 0 && vx > getFriction())
        vx -= getFriction();
    else
        vx = 0.0;
    if(vy > 0 && vy > getFriction())
        vy -= getFriction();
    else
        vy = 0.0;
    if(vx < 0 && vx < -getFriction())
        vx += getFriction();
    else
        vx = 0.0;
    if(vy < 0 && vy < -getFriction())
        vy += getFriction();
    else
        vy = 0.0;
}

std::pair<double, double> Entity::getPosition() const
{
    return {x, y};
}
