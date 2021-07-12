//
// Created by listerily on 2021/7/12.
//

#ifndef STARDEW_VALLEY_LITE_PLAYERCONTROLLER_H
#define STARDEW_VALLEY_LITE_PLAYERCONTROLLER_H

class GameWorld;
class PlayerController
{
private:
    GameWorld& world;
public:
    explicit PlayerController(GameWorld&);

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void selectInventorySlot(int);
};


#endif //STARDEW_VALLEY_LITE_PLAYERCONTROLLER_H
