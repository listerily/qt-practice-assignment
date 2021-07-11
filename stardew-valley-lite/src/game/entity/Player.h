//
// Created by listerily on 2021/7/5.
//

#ifndef STARDEW_VALLEY_LITE_PLAYER_H
#define STARDEW_VALLEY_LITE_PLAYER_H

#include "./Entity.h"

class Player : public Entity
{
private:

public:
    std::string getID() const override;
};


#endif //STARDEW_VALLEY_LITE_PLAYER_H
