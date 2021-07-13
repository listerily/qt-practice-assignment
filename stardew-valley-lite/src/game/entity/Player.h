//
// Created by listerily on 2021/7/5.
//

#ifndef STARDEW_VALLEY_LITE_PLAYER_H
#define STARDEW_VALLEY_LITE_PLAYER_H

#include "./Entity.h"

class Inventory;
class Player : public Entity
{
public:
    enum class Facing : int {
        UP, DOWN, LEFT, RIGHT
    };
private:
    int movingVariant;
    Facing facing;
    Inventory* inventory;
public:
    Player(GameWorld&, Scene&);
    ~Player() override;
    std::string getID() const override;
    Facing getFacing() const;
    bool isMoving() const;
    void move(double, double) override;
    void tick() override;
    void walk(double, double);
    Inventory& getInventory();
    const Inventory& getInventory() const;
private:
    bool isWalkable(double, double) const;
    bool isTileWalkable(int, int) const;
    void renewFacing(double, double);
    void addInitialItemsToInventory();
};


#endif //STARDEW_VALLEY_LITE_PLAYER_H
