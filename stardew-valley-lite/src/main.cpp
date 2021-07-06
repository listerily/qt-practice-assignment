#include <QApplication>
#include <QPushButton>

#include <thread>

#include "ui/gameplaywindow.h"
#include "game/GameClient.h"

int main(int argc, char *argv[])
{
    bool gameShouldExit = false;
    bool tickingThreadTerminated = false;
    QApplication a(argc, argv);
    //Startup game Client
    GameClient gameClient(a);
    GamePlayWindow mainWindow;
    std::thread([&gameClient, &mainWindow, &gameShouldExit, &tickingThreadTerminated](){
        while(!gameShouldExit) {
            gameClient.tick();
            //tick for main window
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        tickingThreadTerminated = true;
    }).detach();
    //Startup UI
    mainWindow.show();
    int returnValue = QApplication::exec();
    gameShouldExit = true;
    while(!tickingThreadTerminated);
    return returnValue;
}
