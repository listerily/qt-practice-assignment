//
// Created by listerily on 2021/7/5.
//

#include "GameWorld.h"

#include <algorithm>

#include "../entity/Player.h"
#include "../GameClient.h"
#include "../config/ConfigLoader.h"


GameWorld::GameWorld(GameClient & client) : client(client), playerController(*this)
{
    player = 0;
}

void GameWorld::registerNewScene(const SceneMapConfig & config)
{
    if(currentScene.empty())
        currentScene = config.id;
    auto newDimension = std::make_unique<Scene>(config);
    scenes[config.id] = std::move(newDimension);
}

Scene &GameWorld::getCurrentGameScene()
{
    return *scenes.find(currentScene)->second;
}

const Scene &GameWorld::getCurrentGameScene() const
{
    return *scenes.find(currentScene)->second;
}

Player &GameWorld::getPlayer()
{
    return dynamic_cast<Player&>(*entities[player]);
}

const Player &GameWorld::getPlayer() const
{
    return dynamic_cast<const Player&>(*entities[player]);
}

void GameWorld::initialize()
{
    const auto& dimMaps = client.getConfigLoader().getSceneMaps();
    for(const auto& dimMap : dimMaps)
        registerNewScene(dimMap);
    initializePlayer();
}

void GameWorld::addNewEntity(std::unique_ptr<Entity> newEntity)
{
    entities.push_back(std::move(newEntity));
}

void GameWorld::removeEntity(const Entity * entityPointer)
{
    for(auto iter = entities.begin(); iter != entities.end();)
    {
        iter = std::remove_if(iter, entities.end(),[&entityPointer](const std::unique_ptr<Entity>& ref){
            return ref.get() == entityPointer;
        });
    }
}

void GameWorld::initializePlayer()
{
    auto thePlayer = std::make_unique<Player>(*this, getCurrentGameScene());
    addNewEntity(std::move(thePlayer));
}

Scene *GameWorld::getSceneByID(const std::string& id)
{
    return scenes.find(id)->second.get();
}

const Scene *GameWorld::getSceneByID(const std::string& id) const
{
    return scenes.find(id)->second.get();
}

void GameWorld::tick()
{
    std::for_each(scenes.begin(), scenes.end(), [](const std::unordered_map<std::string,std::unique_ptr<Scene>>::value_type& dimension){
        dimension.second->tick();
    });
    std::for_each(entities.begin(), entities.end(), [](const std::unique_ptr<Entity>& entity){
        entity->tick();
    });
}

PlayerController &GameWorld::getPlayerController()
{
    return playerController;
}
