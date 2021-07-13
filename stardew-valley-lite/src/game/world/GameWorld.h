//
// Created by listerily on 2021/7/5.
//

#ifndef STARDEW_VALLEY_LITE_GAMEWORLD_H
#define STARDEW_VALLEY_LITE_GAMEWORLD_H

#include <memory>
#include <vector>
#include <list>
#include <unordered_map>

#include "Scene.h"

#include "../entity/Entity.h"
#include "PlayerController.h"

class GameClient;
class SceneMapConfig;
class Entity;
class PlayerController;
class Player;
class GameWorld
{
private:
    GameClient& client;
    std::unordered_map<std::string, std::unique_ptr<Scene>> scenes;
    std::vector<std::unique_ptr<Entity>> entities;
    std::string currentScene;
    std::size_t player;
    PlayerController playerController;
public:
    explicit GameWorld(GameClient&);

    void initialize();

    Scene& getCurrentGameScene();
    const Scene& getCurrentGameScene() const;
    Player& getPlayer();
    const Player& getPlayer() const;
    void addNewEntity(std::unique_ptr<Entity>);
    void removeEntity(const Entity*);
    Scene* getSceneByID(std::string const& id);
    const Scene* getSceneByID(const std::string& id) const;
    void tick();
    PlayerController& getPlayerController();
private:
    void initializePlayer();
    void registerNewScene(SceneMapConfig const&);
};


#endif //STARDEW_VALLEY_LITE_GAMEWORLD_H
