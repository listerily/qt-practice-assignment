//
// Created by listerily on 2021/7/13.
//

#include "ItemInstance.h"

#include "../item/Item.h"
#include "../item/ItemManager.h"

ItemInstance::ItemInstance(const Item * item, unsigned int count, int aux) : item(item), count(count), aux(aux)
{

}

const Item *ItemInstance::getItem() const
{
    return item;
}

unsigned int ItemInstance::getCount() const
{
    return count;
}

void ItemInstance::add(unsigned int amount)
{
    count += amount;
}

void ItemInstance::reduce(unsigned int amount)
{
    if(amount > count)
        count = 0;
    else
        count -= amount;
}

const std::string& ItemInstance::getDisplayTexture() const
{
    return item->getTexture();
}

bool ItemInstance::empty() const
{
    return item == nullptr;
}

void ItemInstance::clear()
{
    item = nullptr;
    count = 0;
    aux = 0;
}

bool ItemInstance::itemMatches(const ItemInstance & rhs) const
{
    return item == rhs.item;
}

bool ItemInstance::itemAndAuxMatches(const ItemInstance & rhs) const
{
    return item == rhs.item && aux == rhs.aux;
}

bool ItemInstance::operator==(const ItemInstance &rhs) const
{
    return allMatches(rhs);
}

bool ItemInstance::allMatches(const ItemInstance & rhs) const
{
    return item == rhs.item && aux == rhs.aux && count == rhs.count;
}

void ItemInstance::reset()
{
    clear();
}

void ItemInstance::reset(const ItemInstance & rhs)
{
    item = rhs.item;
    count = rhs.count;
    aux = rhs.aux;
}

ItemInstance::ItemInstance(const std::string &id, unsigned int c, int a)
{
    item = ItemManager::getInstance().lookup(id);
    count = c;
    aux = a;
}
