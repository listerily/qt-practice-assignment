//
// Created by listerily on 2021/7/5.
//

#ifndef STARDEW_VALLEY_LITE_GAMECLIENT_H
#define STARDEW_VALLEY_LITE_GAMECLIENT_H

class QApplication;
class GameClient
{
private:
    QApplication& app;
    bool gameShouldExit;
public:
    explicit GameClient(QApplication&);
    void tick();
    bool isGameShouldExit() const;
};


#endif //STARDEW_VALLEY_LITE_GAMECLIENT_H
