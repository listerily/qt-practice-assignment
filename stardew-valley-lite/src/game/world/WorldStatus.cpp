//
// Created by listerily on 2021/7/15.
//

#include "WorldStatus.h"

void WorldStatus::set(WorldStatus::Status status)
{
    current = status;
    if(hasUpTime())
        time = getUpTime();
}

void WorldStatus::tick()
{
    if(time > 0 && --time == 0)
        set(getNextStatus());
}

WorldStatus::Status WorldStatus::get() const
{
    return current;
}

bool WorldStatus::hasUpTime() const
{
    switch (current)
    {
        case SWITCHING_SCENE:
        case SLEEPING:
            return true;
        default:;
    }
    return false;
}

int WorldStatus::getUpTime() const
{
    switch (current)
    {
        case SWITCHING_SCENE:
        case SLEEPING:
            return 40;
        default:;
    }
    return 0;
}

WorldStatus::Status WorldStatus::getNextStatus() const
{
    switch (current)
    {
        case SWITCHING_SCENE:
        case SLEEPING:
            return PLAYING;
        default:;
    }
    return WorldStatus::UNSET;
}

WorldStatus::WorldStatus()
{
    time = 0;
    current = UNSET;
}

double WorldStatus::getProgress() const
{
    return 1.0 - (double)time / getUpTime();
}
