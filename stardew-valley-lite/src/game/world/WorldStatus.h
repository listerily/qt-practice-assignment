//
// Created by listerily on 2021/7/15.
//

#ifndef STARDEW_VALLEY_LITE_WORLDSTATUS_H
#define STARDEW_VALLEY_LITE_WORLDSTATUS_H

class WorldStatus
{
public:
    enum Status : int
    {
        UNSET, PLAYING, SWITCHING_SCENE, SLEEPING
    };

    void set(Status);

    void tick();

    Status get() const;

    double getProgress() const;

    WorldStatus();

private:
    Status current;
    int time;

    bool hasUpTime() const;

    int getUpTime() const;

    Status getNextStatus() const;
};


#endif //STARDEW_VALLEY_LITE_WORLDSTATUS_H
