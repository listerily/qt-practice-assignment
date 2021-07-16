//
// Created by listerily on 2021/7/15.
//

#include "Action.h"

void Action::tick(GameWorld &w, Scene &s, Player &p)
{
    if (!started)
    {
        started = true;
        time = getDuration();
        onActionStart(w, s, p);
    }
    if (time > 0 && --time == 0)
        onActionEnd(w, s, p);
}

bool Action::isFinished() const
{
    return time == 0 && started;
}

int Action::getDuration() const
{
    return 0;
}

int Action::getProgressI() const
{
    return getDuration() - time;
}

double Action::getProgressD() const
{
    return (double) getProgressI() / getDuration();
}

void Action::onActionStart(GameWorld &w, Scene &s, Player &p)
{

}

void Action::onActionEnd(GameWorld &w, Scene &s, Player &p)
{

}
