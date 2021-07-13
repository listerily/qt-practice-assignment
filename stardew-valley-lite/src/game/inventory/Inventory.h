//
// Created by listerily on 2021/7/12.
//

#ifndef STARDEW_VALLEY_LITE_INVENTORY_H
#define STARDEW_VALLEY_LITE_INVENTORY_H

#include <vector>

#include "ItemInstance.h"

class Inventory
{
private:
    std::vector<ItemInstance> itemInstances;
    unsigned int selectedSlot;
public:
    explicit Inventory(unsigned int size);
    ~Inventory() = default;

    void setSelectedSlot(unsigned int slot);
    unsigned int getSelectedSlot() const;
    ItemInstance* getSelectedItemInstance();
    const ItemInstance* getSelectedItemInstance() const;
    ItemInstance* get(unsigned int slot);
    const ItemInstance* get(unsigned int slot) const;
    bool addItemInstance(const ItemInstance &item);
    unsigned int getEmptySlotsCount() const;
    void clearSlot(unsigned int slot);
    void clearAll();
    void reduceSelectedItem(unsigned int count);
    void setSlot(unsigned int slot, const ItemInstance&);
    const std::vector<ItemInstance>& getItemInstances() const;
    std::vector<ItemInstance>& getItemInstances();
};


#endif //STARDEW_VALLEY_LITE_INVENTORY_H
