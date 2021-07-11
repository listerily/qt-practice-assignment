//
// Created by listerily on 2021/7/5.
//

#include "GameWorld.h"

GameWorld::GameWorld(GameClient & client) : client(client)
{
    currentDimension = nullptr;
    player = nullptr;
}

void GameWorld::registerNewDimension(const DimMapConfig & config)
{

}

GameDimension &GameWorld::getCurrentGameDimension()
{
    return *currentDimension;
}

const GameDimension &GameWorld::getCurrentGameDimension() const
{
    return *currentDimension;
}

Player &GameWorld::getPlayer()
{
    return *player;
}

const Player &GameWorld::getPlayer() const
{
    return *player;
}
