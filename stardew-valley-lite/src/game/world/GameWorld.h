//
// Created by listerily on 2021/7/5.
//

#ifndef STARDEW_VALLEY_LITE_GAMEWORLD_H
#define STARDEW_VALLEY_LITE_GAMEWORLD_H

#include <memory>
#include <vector>
#include <list>
#include <unordered_map>

#include "GameDimension.h"

#include "../entity/Entity.h"
#include "PlayerController.h"

class GameClient;
class DimMapConfig;
class Entity;
class PlayerController;
class Player;
class GameWorld
{
private:
    GameClient& client;
    std::unordered_map<std::string, std::unique_ptr<GameDimension>> dimensions;
    std::vector<std::unique_ptr<Entity>> entities;
    std::string currentDimension;
    std::size_t player;
    PlayerController playerController;
public:
    explicit GameWorld(GameClient&);

    void initialize();

    GameDimension& getCurrentGameDimension();
    const GameDimension& getCurrentGameDimension() const;
    Player& getPlayer();
    const Player& getPlayer() const;
    void addNewEntity(std::unique_ptr<Entity>);
    void removeEntity(const Entity*);
    GameDimension* getDimensionByID(std::string const& id);
    const GameDimension* getDimensionByID(const std::string& id) const;
    void tick();
    PlayerController& getPlayerController();
private:
    void initializePlayer();
    void registerNewDimension(DimMapConfig const&);
};


#endif //STARDEW_VALLEY_LITE_GAMEWORLD_H
