#include <QApplication>
#include <QPushButton>

#include <thread>

#include "ui/gameplaywindow.h"
#include "game/GameClient.h"

int main(int argc, char *argv[])
{
    bool gameShouldExit = false;
    QApplication a(argc, argv);
    //Startup game Client
    GameClient gameClient(a);
    GamePlayWindow mainWindow(gameClient);
    std::thread([&gameClient, &mainWindow, &gameShouldExit](){
        while(!gameShouldExit) {
            gameClient.tick();
            mainWindow.notifyPaintTick();
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
        }
    }).detach();
    //Startup UI
    mainWindow.show();
    int returnValue = QApplication::exec();
    gameShouldExit = true;
    return returnValue;
}
