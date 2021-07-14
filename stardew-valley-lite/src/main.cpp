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
        using std::chrono::operator""ms;
        while(!gameShouldExit) {
            const auto currentTime = std::chrono::system_clock::now();
            const auto tillTime = currentTime + 20ms;
            gameClient.tick();
            mainWindow.notifyPaintTick();
            std::this_thread::sleep_until(tillTime);
        }
    }).detach();
    //Startup UI
    mainWindow.show();
    int returnValue = QApplication::exec();
    gameShouldExit = true;
    return returnValue;
}
