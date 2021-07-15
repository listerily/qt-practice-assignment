//
// Created by listerily on 2021/7/15.
//

#ifndef STARDEW_VALLEY_LITE_PLAYERSTATUS_H
#define STARDEW_VALLEY_LITE_PLAYERSTATUS_H

#include "Player.h"

class Player;
class Item;
class PlayerStatus
{
public:
    enum Status {
        NONE, PICKUP, EATING, USE_TOOL
    };

    PlayerStatus();
    void setPickup(const Item*);
    void setEating(const Item*);
    void setUsingTool(const Item*, Player::Facing);
    void tick();
    bool isInStatus() const;
    int getProgress() const;
    int getDuration() const;
    Status getStatus() const;
    const Item* getStatusItem() const;
    Player::Facing getStatusFacing() const;
private:
    Status current;
    int time;
    const Item* item;
    Player::Facing facing;
};


#endif //STARDEW_VALLEY_LITE_PLAYERSTATUS_H
