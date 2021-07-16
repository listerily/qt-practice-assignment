//
// Created by listerily on 2021/7/5.
//

#include "Entity.h"

Entity::Entity(Scene &scene) : scene(&scene)
{
    x = y = 0.0;
    health = 0x7fffffff;
}

Entity::~Entity()
= default;

void Entity::tick(GameWorld &)
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

int Entity::getHealth() const
{
    return health;
}

void Entity::hurt(GameWorld &world, int hp)
{
    health -= hp;
    if (health <= 0)
        onDeath(world);
}

void Entity::onDeath(GameWorld &)
{

}

std::pair<double, double> Entity::getPosition() const
{
    return {x, y};
}

Scene &Entity::getScene() const
{
    return *scene;
}

void Entity::changeScene(Scene &s)
{
    scene = &s;
}
