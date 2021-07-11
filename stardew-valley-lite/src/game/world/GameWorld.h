//
// Created by listerily on 2021/7/5.
//

#ifndef STARDEW_VALLEY_LITE_GAMEWORLD_H
#define STARDEW_VALLEY_LITE_GAMEWORLD_H

#include <memory>
#include <vector>

#include "GameDimension.h"

class GameClient;
class DimMapConfig;
class GameWorld
{
private:
    GameClient& client;
    std::vector<std::unique_ptr<GameDimension>> dimensions;
    int currentDimensionIndex = 0;
public:
    explicit GameWorld(GameClient&);

    void registerNewDimension(DimMapConfig const&);

    GameDimension& getCurrentGameDimension();
    const GameDimension& getCurrentGameDimension() const;
};


#endif //STARDEW_VALLEY_LITE_GAMEWORLD_H
