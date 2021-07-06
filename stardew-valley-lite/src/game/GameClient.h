//
// Created by listerily on 2021/7/5.
//

#ifndef STARDEW_VALLEY_LITE_GAMECLIENT_H
#define STARDEW_VALLEY_LITE_GAMECLIENT_H

class QApplication;
class GameWorld;
class GameClient
{
private:
    QApplication& app;
    bool gameShouldExit;
    GameWorld* currentWorld;
public:
    explicit GameClient(QApplication&);
    ~GameClient();
    void tick();
    GameWorld* getCurrentWorld();
    const GameWorld* getCurrentWorld() const;
    void createWorld();
};


#endif //STARDEW_VALLEY_LITE_GAMECLIENT_H
