//
// Created by listerily on 2021/7/13.
//

#include "ItemManager.h"

#include "./impl/WoodItem.h"
#include "./impl/WeedsItem.h"
#include "./impl/StoneItem.h"
#include "./impl/StrawberryItem.h"
#include "./impl/AxeItem.h"
#include "./impl/PickaxeItem.h"
#include "./impl/HoeItem.h"
#include "./impl/MixedSeedsItem.h"
#include "./impl/ParsnipItem.h"

void ItemManager::initializeItems()
{
    lookupMap["wood"] = new WoodItem;
    lookupMap["weeds"] = new WeedsItem;
    lookupMap["stone"] = new StoneItem;
    lookupMap["strawberry"] = new StrawberryItem;
    lookupMap["axe"] = new AxeItem;
    lookupMap["pickaxe"] = new PickaxeItem;
    lookupMap["hoe"] = new HoeItem;
    lookupMap["mixed_seeds"] = new MixedSeedItem;
    lookupMap["parsnip"] = new ParsnipItem;
}

const Item *ItemManager::lookup(const std::string &id) const
{
    if (lookupMap.find(id) == lookupMap.end())
        return nullptr;
    return lookupMap.at(id);
}

ItemManager::~ItemManager()
{
    for (const auto &i : lookupMap)
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
