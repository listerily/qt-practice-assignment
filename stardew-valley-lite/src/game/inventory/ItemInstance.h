//
// Created by listerily on 2021/7/13.
//

#ifndef STARDEW_VALLEY_LITE_ITEMINSTANCE_H
#define STARDEW_VALLEY_LITE_ITEMINSTANCE_H

#include <string>

class Item;
class ItemInstance
{
public:
    const Item* item;
    unsigned int count;
    int aux;
public:
    explicit ItemInstance(const Item* = nullptr, unsigned int = 0, int = 0);
    explicit ItemInstance(const std::string& id, unsigned int = 0, int = 0);

    const Item* getItem() const;
    unsigned int getCount() const;
    void add(unsigned int);
    void reduce(unsigned int);
    const std::string& getDisplayTexture() const;
    bool empty() const;
    void clear();
    void reset();
    void reset(const ItemInstance&);

    bool itemMatches(const ItemInstance&) const;
    bool itemAndAuxMatches(const ItemInstance&) const;
    bool allMatches(const ItemInstance&) const;
    bool operator==(const ItemInstance&) const;
};


#endif //STARDEW_VALLEY_LITE_ITEMINSTANCE_H
