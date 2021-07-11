//
// Created by listerily on 2021/7/5.
//

#include "GameWorld.h"

GameWorld::GameWorld(GameClient & client) : client(client)
{

}

void GameWorld::registerNewDimension(const DimMapConfig & config)
{

}

GameDimension &GameWorld::getCurrentGameDimension()
{
    return *dimensions[currentDimensionIndex];
}

const GameDimension &GameWorld::getCurrentGameDimension() const
{
    return *dimensions[currentDimensionIndex];
}
