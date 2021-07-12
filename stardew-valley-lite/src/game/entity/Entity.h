//
// Created by listerily on 2021/7/5.
//

#ifndef STARDEW_VALLEY_LITE_ENTITY_H
#define STARDEW_VALLEY_LITE_ENTITY_H

#include <string>

class GameDimension;
class GameWorld;
class Entity
{
protected:
    double x, y;
    double ax, ay;
    double vx, vy;
    GameWorld& world;
    GameDimension* dimension;
    int health;
public:
    Entity(GameWorld&, GameDimension&);
    virtual ~Entity();

    virtual void tick();
    virtual void move(double, double);
    virtual void moveTo(double, double);
    virtual float getFriction() const;
    virtual std::pair<double, double> getAcceleration() const;
    virtual void applyAcceleration(double, double);
    virtual std::pair<double, double> getVelocity() const;
    virtual std::string getID() const = 0;
    virtual void setDimension(GameDimension&);
    virtual int getHealth() const;
    virtual void hurt(int);
    virtual void onDeath();
    virtual std::pair<double, double> getPosition() const;
private:
    void solveAcceleration();
};


#endif //STARDEW_VALLEY_LITE_ENTITY_H
