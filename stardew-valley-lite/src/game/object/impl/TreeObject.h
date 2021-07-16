//
// Created by listerily on 2021/7/16.
//

#ifndef STARDEW_VALLEY_LITE_TREEOBJECT_H
#define STARDEW_VALLEY_LITE_TREEOBJECT_H

#include "../TileObject.h"

class TreeObject : public TileObject
{
protected:
    int life;
public:
    TreeObject(std::string id, int, int);

    bool ableToInteract() const override;

    std::unique_ptr<Action>
    interact(GameWorld &world, ItemInstance *instance, Player &player, Scene &scene, int x, int y) override;
};


#endif //STARDEW_VALLEY_LITE_TREEOBJECT_H
