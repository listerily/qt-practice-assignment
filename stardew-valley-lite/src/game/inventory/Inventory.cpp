//
// Created by listerily on 2021/7/12.
//

#include "Inventory.h"

Inventory::Inventory(unsigned int size)
{
    itemInstances.resize(size);
    selectedSlot = 0;
}

void Inventory::setSelectedSlot(unsigned int slot)
{
    selectedSlot = slot;
}

unsigned int Inventory::getSelectedSlot() const
{
    return selectedSlot;
}

ItemInstance *Inventory::getSelectedItemInstance()
{
    return get(selectedSlot);
}

const ItemInstance *Inventory::getSelectedItemInstance() const
{
    return get(selectedSlot);
}

ItemInstance *Inventory::get(unsigned int slot)
{
    if(!itemInstances[slot].empty())
        return nullptr;
    return &itemInstances[slot];
}

const ItemInstance *Inventory::get(unsigned int slot) const
{
    if(!itemInstances[slot].empty())
        return nullptr;
    return &itemInstances[slot];
}

bool Inventory::addItemInstance(const ItemInstance & item)
{
    for(auto& instance : itemInstances)
    {
        if(instance.itemAndAuxMatches(item))
        {
            instance.add(item.count);
            return true;
        }
    }

    for(auto& instance : itemInstances)
    {
        if(instance.empty())
        {
            instance.set(item);
            return true;
        }
    }
    return false;
}

unsigned int Inventory::getEmptySlotsCount() const
{
    unsigned int ans = 0;
    for(auto& instance : itemInstances)
        if(instance.empty())
            ++ans;
    return ans;
}

void Inventory::clearSlot(unsigned int slot)
{
    itemInstances[slot].clear();
}

void Inventory::clearAll()
{
    for(auto& instance : itemInstances)
        instance.clear();
}

void Inventory::reduceSelectedItem(unsigned int count)
{
    if(getSelectedItemInstance())
        getSelectedItemInstance()->reduce(count);
}

void Inventory::setSlot(unsigned int slot, const ItemInstance & instance)
{
    itemInstances[slot].set(instance);
}

const std::vector<ItemInstance> &Inventory::getItemInstances() const
{
    return itemInstances;
}

std::vector<ItemInstance> &Inventory::getItemInstances()
{
    return itemInstances;
}

unsigned int Inventory::size() const
{
    return itemInstances.size();
}
