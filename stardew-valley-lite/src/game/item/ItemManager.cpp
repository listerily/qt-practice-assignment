//
// Created by listerily on 2021/7/13.
//

#include "ItemManager.h"

#include "./impl/WoodItem.h"

void ItemManager::initializeItems()
{
    lookupMap["wood"] = ItemManager::wood = new WoodItem();
}

const Item *ItemManager::lookup(const std::string& id) const
{
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

Item* ItemManager::wood = nullptr;