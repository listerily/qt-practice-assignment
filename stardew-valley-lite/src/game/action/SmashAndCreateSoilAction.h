//
// Created by listerily on 2021/7/16.
//

#ifndef STARDEW_VALLEY_LITE_SMASHANDCREATESOILACTION_H
#define STARDEW_VALLEY_LITE_SMASHANDCREATESOILACTION_H

#include "SmashAction.h"

class SmashAndCreateSoilAction : public SmashAction
{
private:
    int x, y;
public:
    SmashAndCreateSoilAction(const Item &, int, int);

    void onActionEnd(GameWorld &w, Scene &s, Player &p) override;
};


#endif //STARDEW_VALLEY_LITE_SMASHANDCREATESOILACTION_H
