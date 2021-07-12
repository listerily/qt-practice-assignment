//
// Created by listerily on 2021/7/5.
//

#include "GameWorld.h"

#include <algorithm>

#include "../entity/Player.h"
#include "../GameClient.h"
#include "../../config/ConfigLoader.h"


GameWorld::GameWorld(GameClient & client) : client(client), playerController(*this)
{
    player = 0;
}

void GameWorld::registerNewDimension(const DimMapConfig & config)
{
    if(currentDimension.empty())
        currentDimension = config.id;
    auto newDimension = std::make_unique<GameDimension>(config);
    dimensions[config.id] = std::move(newDimension);
}

GameDimension &GameWorld::getCurrentGameDimension()
{
    return *dimensions.find(currentDimension)->second;
}

const GameDimension &GameWorld::getCurrentGameDimension() const
{
    return *dimensions.find(currentDimension)->second;
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
    const auto& dimMaps = client.getConfigLoader().getDimMaps();
    for(const auto& dimMap : dimMaps)
        registerNewDimension(dimMap);
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
    auto thePlayer = std::make_unique<Player>(*this, getCurrentGameDimension());
    addNewEntity(std::move(thePlayer));
}

GameDimension *GameWorld::getDimensionByID(const std::string& id)
{
    return dimensions.find(id)->second.get();
}

const GameDimension *GameWorld::getDimensionByID(const std::string& id) const
{
    return dimensions.find(id)->second.get();
}

void GameWorld::tick()
{
    std::for_each(dimensions.begin(), dimensions.end(), [](const std::unordered_map<std::string,std::unique_ptr<GameDimension>>::value_type& dimension){
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
