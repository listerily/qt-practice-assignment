//
// Created by listerily on 2021/7/13.
//

#ifndef STARDEW_VALLEY_LITE_ITEM_H
#define STARDEW_VALLEY_LITE_ITEM_H

#include <string>

class Player;
class TileObject;
class ItemInstance;
class Item
{
private:
    std::string id;
public:
    explicit Item(std::string);
    virtual ~Item() = default;
    virtual void playerInteract(Player&, ItemInstance&, TileObject&) const;
    virtual void playerInteract(Player&, ItemInstance&) const;
    virtual bool isSelfAbleToInteract() const;
    virtual bool isOnObjectAbleToInteract() const;
    virtual const std::string& getTexture()const = 0;
};


#endif //STARDEW_VALLEY_LITE_ITEM_H
