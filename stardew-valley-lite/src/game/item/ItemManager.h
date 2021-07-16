//
// Created by listerily on 2021/7/13.
//

#ifndef STARDEW_VALLEY_LITE_ITEMMANAGER_H
#define STARDEW_VALLEY_LITE_ITEMMANAGER_H

#include <string>
#include <unordered_map>

class Item;

class ItemManager
{
private:
    std::unordered_map<std::string, const Item *> lookupMap;
public:
    const Item *lookup(const std::string &id) const;

    static const ItemManager &getInstance();

private:
    ItemManager();

    ~ItemManager();

    void initializeItems();
};


#endif //STARDEW_VALLEY_LITE_ITEMMANAGER_H
