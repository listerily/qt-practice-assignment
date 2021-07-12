//
// Created by listerily on 2021/7/5.
//

#ifndef STARDEW_VALLEY_LITE_GAMECLIENT_H
#define STARDEW_VALLEY_LITE_GAMECLIENT_H

class QApplication;
class GameWorld;
class ConfigLoader;
class GameClient
{
private:
    QApplication& app;
    bool gameShouldExit;
    GameWorld* currentWorld;
    ConfigLoader* loader;
public:
    explicit GameClient(QApplication&);
    ~GameClient();
    void tick();
    GameWorld* getCurrentWorld();
    const GameWorld* getCurrentWorld() const;
    void createWorld();
    const ConfigLoader& getConfigLoader() const;
};


#endif //STARDEW_VALLEY_LITE_GAMECLIENT_H
