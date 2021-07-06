#include <QApplication>
#include <QPushButton>

#include <thread>

#include "ui/gamemainwindow.h"
#include "game/GameClient.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Startup game Client
    GameClient gameClient(a);
    GameMainWindow mainWindow;
    std::thread gameClientThread([&gameClient, &mainWindow](){
        while(gameClient.isGameShouldExit()) {
            gameClient.tick();
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
        mainWindow.close();
    });
    //Startup UI
    mainWindow.show();
    return QApplication::exec();
}
