//
// Created by listerily on 2021/7/5.
//

#ifndef STARDEW_VALLEY_LITE_PLAYER_H
#define STARDEW_VALLEY_LITE_PLAYER_H

#include "Entity.h"

#include <list>
#include <memory>

#include "../action/Action.h"

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
    std::unique_ptr<Action> currentAction;
public:
    Player(Scene&);
    ~Player() override;
    Facing getFacing() const;
    bool isMoving() const;
    void move(double, double) override;
    void tick(GameWorld&) override;
    Inventory& getInventory();
    const Inventory& getInventory() const;
    std::pair<int, int> getFacingPosition() const;
    std::list<std::pair<int, int>> getFacingPositions() const;
    void interact(GameWorld&, bool);
    const Action* getCurrentAction() const;
    void setAction(std::unique_ptr<Action>);
protected:
    void addInitialItemsToInventory();
    bool isWalkable(double, double) const;
    bool isTileWalkable(int, int) const;
    void turn(double, double);
    double getCollisionBoxRadius() const;

    friend class PlayerController;
};


#endif //STARDEW_VALLEY_LITE_PLAYER_H
