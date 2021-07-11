//
// Created by listerily on 2021/7/5.
//

#ifndef STARDEW_VALLEY_LITE_GAMEWORLD_H
#define STARDEW_VALLEY_LITE_GAMEWORLD_H

#include <memory>
#include <vector>
#include <list>

#include "GameDimension.h"

class GameClient;
class DimMapConfig;
class Entity;
class Player;
class GameWorld
{
private:
    GameClient& client;
    std::list<std::unique_ptr<GameDimension>> dimensions;
    std::list<std::unique_ptr<Entity>> entities;
    GameDimension* currentDimension;
    Player* player;
public:
    explicit GameWorld(GameClient&);

    void registerNewDimension(DimMapConfig const&);

    GameDimension& getCurrentGameDimension();
    const GameDimension& getCurrentGameDimension() const;
    Player& getPlayer();
    const Player& getPlayer() const;
};


#endif //STARDEW_VALLEY_LITE_GAMEWORLD_H
