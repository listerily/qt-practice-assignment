//
// Created by listerily on 2021/7/5.
//

#include "GameClient.h"

#include <Qt>

#include "world/GameWorld.h"
#include "config/ConfigLoader.h"
#include "item/ItemManager.h"
#include "InputHandler.h"

GameClient::GameClient(QApplication& app): app(app)
{
    gameShouldExit = false;
    currentWorld = nullptr;
    loader = new ConfigLoader(app);
    loader->initialize();
    inputHandler = new InputHandler;

    createWorld();
}

void GameClient::tick()
{
    if(currentWorld)
        currentWorld->tick();
    processKeyboardInput();
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
    delete inputHandler;
}

const ConfigLoader &GameClient::getConfigLoader() const
{
    return *loader;
}

InputHandler &GameClient::getInputHandler()
{
    return *inputHandler;
}

const InputHandler &GameClient::getInputHandler() const
{
    return *inputHandler;
}

void GameClient::processKeyboardInput()
{
    const bool up = inputHandler->isKeyPressed(Qt::Key_W);
    const bool down = inputHandler->isKeyPressed(Qt::Key_S);
    const bool left = inputHandler->isKeyPressed(Qt::Key_A);
    const bool right = inputHandler->isKeyPressed(Qt::Key_D);
    if(currentWorld)
        currentWorld->getPlayerController().walk(up, down, left, right);
}
