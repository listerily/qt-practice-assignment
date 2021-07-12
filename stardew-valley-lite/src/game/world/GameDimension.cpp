//
// Created by listerily on 2021/7/5.
//

#include "GameDimension.h"

#include <algorithm>

#include "../../config/DimMapConfig.h"
#include "object/factory/TileObjectFactory.h"
#include "TileSheet.h"

std::list<std::unique_ptr<TileObject>> &GameDimension::getObjects()
{
    return objects;
}

const std::list<std::unique_ptr<TileObject>> &GameDimension::getObjects() const
{
    return objects;
}

void GameDimension::tick()
{
    std::for_each(objects.begin(), objects.end(), [](const std::unique_ptr<TileObject>& object){
        object->tick();
    });
}

const std::string &GameDimension::getID() const
{
    return id;
}

GameDimension::GameDimension(const DimMapConfig &config) : id(config.id)
{
    tileSheet = new TileSheet;
    initialize(config);
}

void GameDimension::initialize(const DimMapConfig& config)
{
    for(const auto& object : config.objects)
    {
        auto newObject = TileObjectFactory::generateTileObjectByIdAt(object.id, object.posX, object.posY);
        addNewObject(std::move(newObject));
    }
}

void GameDimension::addNewObject(std::unique_ptr<TileObject> newObject)
{
    tileSheet->onTileObjectAdded(*newObject);
    objects.insert(objects.end(), std::move(newObject));
}

void GameDimension::removeObject(const TileObject * target)
{
    tileSheet->onTileObjectRemoved(*target);
    objects.remove_if([&target](const std::unique_ptr<TileObject>& object){
        return object.get() == target;
    });
}

const TileSheet &GameDimension::getTileSheet() const
{
    return *tileSheet;
}

GameDimension::~GameDimension()
{
    delete tileSheet;
}
