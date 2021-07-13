//
// Created by listerily on 2021/7/5.
//

#ifndef STARDEW_VALLEY_LITE_ENTITY_H
#define STARDEW_VALLEY_LITE_ENTITY_H

#include <string>

class Scene;
class GameWorld;
class Entity
{
protected:
    double x, y;
    double ax, ay;
    double vx, vy;
    GameWorld& world;
    Scene* scene;
    int health;
public:
    Entity(GameWorld&, Scene&);
    virtual ~Entity();

    virtual void tick();
    virtual void move(double, double);
    virtual void moveTo(double, double);
    virtual std::string getID() const = 0;
    virtual void setScene(Scene&);
    virtual int getHealth() const;
    virtual void hurt(int);
    virtual void onDeath();
    virtual std::pair<double, double> getPosition() const;
};


#endif //STARDEW_VALLEY_LITE_ENTITY_H
