//
// Created by listerily on 2021/7/15.
//

#ifndef STARDEW_VALLEY_LITE_ACTION_H
#define STARDEW_VALLEY_LITE_ACTION_H

class Scene;

class Player;

class GameWorld;

class Action
{
protected:
    int time = 0;
    bool started = false;
public:
    Action() = default;

    virtual ~Action() = default;

    virtual void tick(GameWorld &w, Scene &s, Player &p);

    virtual bool isFinished() const;

    virtual int getDuration() const;

    virtual int getProgressI() const;

    virtual double getProgressD() const;

    virtual void onActionStart(GameWorld &w, Scene &s, Player &p);

    virtual void onActionEnd(GameWorld &w, Scene &s, Player &p);
};


#endif //STARDEW_VALLEY_LITE_ACTION_H
