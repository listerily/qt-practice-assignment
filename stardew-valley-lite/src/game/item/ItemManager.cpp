//
// Created by listerily on 2021/7/13.
//

#include "ItemManager.h"

#include "./impl/WoodItem.h"
#include "./impl/WeedsItem.h"
#include "./impl/StoneItem.h"
#include "./impl/StrawberryItem.h"
#include "./impl/AxeItem.h"

void ItemManager::initializeItems()
{
    lookupMap["wood"] = new WoodItem;
    lookupMap["weeds"] = new WeedsItem;
    lookupMap["stone"] = new StoneItem;
    lookupMap["strawberry"] = new StrawberryItem;
    lookupMap["axe"] = new AxeItem;
}

const Item *ItemManager::lookup(const std::string& id) const
{
    if(lookupMap.find(id) == lookupMap.end())
        return nullptr;
    return lookupMap.at(id);
}

ItemManager::~ItemManager()
{
    for(const auto& i : lookupMap)
        delete i.second;
}

ItemManager::ItemManager()
{
    initializeItems();
}

const ItemManager &ItemManager::getInstance()
{
    static const ItemManager instance;
    return instance;
}
