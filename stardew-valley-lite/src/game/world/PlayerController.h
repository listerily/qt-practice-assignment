//
// Created by listerily on 2021/7/12.
//

#ifndef STARDEW_VALLEY_LITE_PLAYERCONTROLLER_H
#define STARDEW_VALLEY_LITE_PLAYERCONTROLLER_H

#include "../entity/Player.h"

class GameWorld;

class Inventory;

class Player;

class PlayerController
{
private:
    GameWorld &world;
public:
    explicit PlayerController(GameWorld &);

    void walk(bool, bool, bool, bool);

    void walkUp(double);

    void walkDown(double);

    void walkLeft(double);

    void walkRight(double);

    void selectInventorySlot(int);

    Inventory &getInventory();

    const Inventory &getInventory() const;

    void interact(bool);

    void turn(Player::Facing);

private:
    void walk(double, double);

    bool isInSilent() const;
};


#endif //STARDEW_VALLEY_LITE_PLAYERCONTROLLER_H
