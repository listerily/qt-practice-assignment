//
// Created by listerily on 2021/7/5.
//

#include "GameClient.h"

#include <Qt>

#include "world/GameWorld.h"
#include "config/ConfigLoader.h"
#include "item/ItemManager.h"
#include "InputHandler.h"
#include "src/game/world/WorldStatus.h"

GameClient::GameClient(QApplication &app) : app(app)
{
    gameShouldExit = false;
    currentWorld = nullptr;
    loader = new ConfigLoader(app);
    loader->initialize();
    inputHandler = new InputHandler;
    interactCoolDown = 0;
}

void GameClient::tick()
{
    if (gameShouldExit || !currentWorld)
        return;
    worldLock.lock();
    currentWorld->tick();
    processKeyboardInput();
    worldLock.unlock();
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
    worldLock.lock();
    delete currentWorld;
    currentWorld = new GameWorld(*this);
    currentWorld->initialize();
    worldLock.unlock();
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
    const bool up = inputHandler->isKeyPressed(Qt::Key_W) || inputHandler->isKeyPressed(Qt::Key_Up);
    const bool down = inputHandler->isKeyPressed(Qt::Key_S) || inputHandler->isKeyPressed(Qt::Key_Down);
    const bool left = inputHandler->isKeyPressed(Qt::Key_A) || inputHandler->isKeyPressed(Qt::Key_Left);
    const bool right = inputHandler->isKeyPressed(Qt::Key_D) || inputHandler->isKeyPressed(Qt::Key_Right);
    currentWorld->getPlayerController().walk(up, down, left, right);
}
