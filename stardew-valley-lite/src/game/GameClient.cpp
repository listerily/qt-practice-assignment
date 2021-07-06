//
// Created by listerily on 2021/7/5.
//

#include "GameClient.h"

GameClient::GameClient(QApplication& app): app(app)
{
    gameShouldExit = false;
}

void GameClient::tick()
{

}

bool GameClient::isGameShouldExit() const
{
    return gameShouldExit;
}
