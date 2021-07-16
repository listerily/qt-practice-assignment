#include <QApplication>
#include <QPushButton>

#include <thread>

#include "ui/gameplaywindow.h"
#include "ui/gamestartwindow.h"
#include "game/GameClient.h"

GamePlayWindow *globalGamePlayWindow = nullptr;

int main(int argc, char *argv[])
{
    bool gameShouldExit = false;
    QApplication a(argc, argv);
    GameClient gameClient(a);
    GameStartWindow startWindow(gameClient);
    startWindow.show();

    //Startup game Client
    std::thread([&gameClient, &gameShouldExit]()
                {
                    using std::chrono::operator ""ms;
                    while (!gameShouldExit)
                    {
                        const auto currentTime = std::chrono::system_clock::now();
                        const auto tillTime = currentTime + 20ms;
                        gameClient.tick();
                        if (globalGamePlayWindow)
                            globalGamePlayWindow->notifyPaintTick();
                        std::this_thread::sleep_until(tillTime);
                    }
                }).detach();
    int returnValue = QApplication::exec();
    gameShouldExit = true;
    delete globalGamePlayWindow;
    return returnValue;
}
