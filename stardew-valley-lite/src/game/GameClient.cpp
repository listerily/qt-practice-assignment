//
// Created by listerily on 2021/7/5.
//

#include "GameClient.h"

#include "world/GameWorld.h"

GameClient::GameClient(QApplication& app): app(app)
{
    gameShouldExit = false;
    currentWorld = nullptr;

    createWorld();
}

void GameClient::tick()
{
}

GameWorld *GameClient::getCurrentWorld()
{
    return currentWorld;
}

const GameWorld *GameClient::getCurrentWorld() const
{
    return currentWorld;
}

void GameClient::createWorld()
{
    delete currentWorld;
    currentWorld = new GameWorld;
}

GameClient::~GameClient()
{
    delete currentWorld;
}
