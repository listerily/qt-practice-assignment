//
// Created by listerily on 2021/7/5.
//

#include "GameClient.h"

#include "world/GameWorld.h"
#include "../config/ConfigLoader.h"


GameClient::GameClient(QApplication& app): app(app)
{
    gameShouldExit = false;
    currentWorld = nullptr;
    loader = new ConfigLoader(app);
    loader->initialize();

    createWorld();
}

void GameClient::tick()
{
    if(currentWorld)
        currentWorld->tick();
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
    currentWorld = new GameWorld(*this);
    currentWorld->initialize();
}

GameClient::~GameClient()
{
    delete currentWorld;
    delete loader;
}

const ConfigLoader &GameClient::getConfigLoader() const
{
    return *loader;
}
