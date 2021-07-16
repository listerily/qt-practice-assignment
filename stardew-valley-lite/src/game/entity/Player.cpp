//
// Created by listerily on 2021/7/5.
//

#include "Player.h"

#include <cmath>

#include "../world/TileSheet.h"
#include "../world/Scene.h"
#include "../item/Item.h"
#include "../object/TileObject.h"
#include "../inventory/Inventory.h"

Player::Player(Scene &s) : Entity(s)
{
    facing = Facing::DOWN;
    movingVariant = 0;
    inventory = new Inventory(8);
    currentAction = nullptr;

    addInitialItemsToInventory();
}

Player::Facing Player::getFacing() const
{
    return facing;
}

bool Player::isMoving() const
{
    return movingVariant > 0;
}

void Player::move(double x, double y)
{
    Entity::move(x, y);
    movingVariant = 3;
}

void Player::tick(GameWorld &world)
{
    Entity::tick(world);
    if (movingVariant > 0)
        --movingVariant;
    if (currentAction)
    {
        currentAction->tick(world, getScene(), *this);
        if (currentAction->isFinished())
            currentAction = nullptr;
    }
}

bool Player::isWalkable(double x, double y) const
{
    const double collisionBoxRadius = getCollisionBoxRadius();
    return isTileWalkable(floor(x - collisionBoxRadius), floor(y - collisionBoxRadius)) &&
           isTileWalkable(floor(x + collisionBoxRadius), floor(y + collisionBoxRadius)) &&
           isTileWalkable(floor(x - collisionBoxRadius), floor(y + collisionBoxRadius)) &&
           isTileWalkable(floor(x + collisionBoxRadius), floor(y - collisionBoxRadius));
}

bool Player::isTileWalkable(int x, int y) const
{
    const auto &tiles = getScene().getTileSheet().getTilesAt(x, y);
    if (tiles.empty())
        return true;
    bool able = true;
    for (const auto &tile : tiles)
    {
        switch (tile.tile->walkable)
        {
            case Tile::WalkableType::FORCED_DISABLE:
                return false;
            case Tile::WalkableType::DISABLE:
                able = false;
                break;
            case Tile::WalkableType::ABLE:
                break;
            case Tile::WalkableType::FORCED_ABLE:
                able = true;
                break;
        }

    }
    return able;
}

void Player::turn(double x, double y)
{
    if (x > 0.0 && y == 0.0)
        facing = Facing::RIGHT;
    if (x < 0.0 && y == 0.0)
        facing = Facing::LEFT;
    if (x == 0.0 && y > 0.0)
        facing = Facing::DOWN;
    if (x == 0.0 && y < 0.0)
        facing = Facing::UP;
}

Inventory &Player::getInventory()
{
    return *inventory;
}

const Inventory &Player::getInventory() const
{
    return *inventory;
}

Player::~Player()
{
    delete inventory;
}

void Player::addInitialItemsToInventory()
{
    inventory->addItemInstance(ItemInstance("axe", 1));
    inventory->addItemInstance(ItemInstance("pickaxe", 1));
    inventory->addItemInstance(ItemInstance("hoe", 1));
}

std::pair<int, int> Player::getFacingPosition() const
{
    switch (getFacing())
    {
        case Facing::UP:
            return {floor(x), floor(y) - 1};
        case Facing::DOWN:
            return {floor(x), floor(y) + 1};
        case Facing::LEFT:
            return {floor(x) - 1, floor(y)};
        case Facing::RIGHT:
            return {floor(x) + 1, floor(y)};
    }
    return {0, 0};
}

std::list<std::pair<int, int>> Player::getFacingPositions() const
{
    const double collisionBoxRadius = getCollisionBoxRadius();
    switch (getFacing())
    {
        case Facing::UP:
            return {{floor(x - collisionBoxRadius), floor(y) - 1},
                    {floor(x + collisionBoxRadius), floor(y) - 1}};
        case Facing::DOWN:
            return {{floor(x - collisionBoxRadius), floor(y) + 1},
                    {floor(x + collisionBoxRadius), floor(y) + 1}};
        case Facing::LEFT:
            return {{floor(x) - 1, floor(y - collisionBoxRadius)},
                    {floor(x) - 1, floor(y + collisionBoxRadius)}};
        case Facing::RIGHT:
            return {{floor(x) + 1, floor(y - collisionBoxRadius)},
                    {floor(x) + 1, floor(y + collisionBoxRadius)}};
    }
    return {{0, 0}};
}

double Player::getCollisionBoxRadius()
{
    return 0.3;
}

void Player::interact(GameWorld &world, bool self)
{
    if (getCurrentAction())
        return;
    ItemInstance *selectedItem = getInventory().getSelectedItemInstance();
    if (self && selectedItem)
    {
        auto theAction = selectedItem->item->interact(*this, *selectedItem);
        setAction(std::move(theAction));
    } else if (!self)
    {
        const auto &facingPosition = getFacingPosition();
        auto &tileObjects = getScene().getTileSheet().getTilesAndObjectsCoveredAt(facingPosition.first,
                                                                                  facingPosition.second);
        for (auto tileObject = tileObjects.rbegin(); tileObject != tileObjects.rend(); ++tileObject)
        {
            if ((tileObject->second)->ableToInteract())
            {
                auto theAction = (tileObject->second)->interact(world, selectedItem, *this, getScene(),
                                                                facingPosition.first,
                                                                facingPosition.second);
                setAction(std::move(theAction));
                if (selectedItem && !selectedItem->empty())
                    selectedItem->item->onInteract(*this, *selectedItem, *tileObject->second);
                break;
            }
        }
    }
}

const Action *Player::getCurrentAction() const
{
    return currentAction.get();
}

void Player::setAction(std::unique_ptr<Action> action)
{
    currentAction = std::move(action);
}
