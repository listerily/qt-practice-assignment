//
// Created by listerily on 2021/7/16.
//

#ifndef STARDEW_VALLEY_LITE_SMASHANDGETACTION_H
#define STARDEW_VALLEY_LITE_SMASHANDGETACTION_H

#include "SmashAction.h"

class SmashAndGetAction : public SmashAction
{
private:
    const ItemInstance harvest;
    TileObject &tileObject;
    bool shouldRemoveObject;
public:
    SmashAndGetAction(const Item &, const ItemInstance &, TileObject &, bool);

    void onActionEnd(GameWorld &w, Scene &s, Player &p) override;
};


#endif //STARDEW_VALLEY_LITE_SMASHANDGETACTION_H
