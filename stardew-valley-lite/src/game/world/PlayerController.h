//
// Created by listerily on 2021/7/12.
//

#ifndef STARDEW_VALLEY_LITE_PLAYERCONTROLLER_H
#define STARDEW_VALLEY_LITE_PLAYERCONTROLLER_H

class GameWorld;
class Inventory;
class PlayerController
{
private:
    GameWorld& world;
public:
    explicit PlayerController(GameWorld&);

    void walkUp();
    void walkDown();
    void walkLeft();
    void walkRight();
    void selectInventorySlot(int);
    Inventory& getInventory();
    const Inventory& getInventory() const;
};


#endif //STARDEW_VALLEY_LITE_PLAYERCONTROLLER_H
