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
    int health;
    Scene *scene;
public:
    explicit Entity(Scene &);

    virtual ~Entity();

    virtual void tick(GameWorld &);

    virtual void move(double, double);

    virtual void moveTo(double, double);

    virtual int getHealth() const;

    virtual void hurt(GameWorld &, int);

    virtual void onDeath(GameWorld &);

    virtual std::pair<double, double> getPosition() const;

    virtual void changeScene(Scene &);

protected:
    virtual Scene &getScene() const;
};


#endif //STARDEW_VALLEY_LITE_ENTITY_H
