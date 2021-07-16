//
// Created by listerily on 2021/7/13.
//

#ifndef STARDEW_VALLEY_LITE_ITEM_H
#define STARDEW_VALLEY_LITE_ITEM_H

#include <string>
#include <memory>

#include "../action/Action.h"

class Player;

class TileObject;

class Action;

class ItemInstance;

class Item
{
private:
    std::string id;
public:
    explicit Item(std::string);

    virtual ~Item() = default;

    virtual void onInteract(Player &, ItemInstance &, TileObject &) const;

    virtual std::unique_ptr<Action> interact(Player &, ItemInstance &) const;

    virtual bool hideWhenCarrying() const;

    virtual const std::string &getTexture() const = 0;
};


#endif //STARDEW_VALLEY_LITE_ITEM_H
