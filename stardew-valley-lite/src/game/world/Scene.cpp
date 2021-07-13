//
// Created by listerily on 2021/7/5.
//

#include "Scene.h"

#include <algorithm>

#include "../config/SceneMapConfig.h"
#include "../object/factory/TileObjectFactory.h"
#include "TileSheet.h"

std::list<std::unique_ptr<TileObject>> &Scene::getObjects()
{
    return objects;
}

const std::list<std::unique_ptr<TileObject>> &Scene::getObjects() const
{
    return objects;
}

void Scene::tick()
{
    std::for_each(objects.begin(), objects.end(), [](const std::unique_ptr<TileObject>& object){
        object->tick();
    });
}

const std::string &Scene::getID() const
{
    return id;
}

Scene::Scene(const SceneMapConfig &config) : id(config.id)
{
    tileSheet = new TileSheet;
    initialize(config);
}

void Scene::initialize(const SceneMapConfig& config)
{
    for(const auto& object : config.objects)
    {
        auto newObject = TileObjectFactory::generateTileObjectByIdAt(object.id, object.posX, object.posY);
        addNewObject(std::move(newObject));
    }
}

void Scene::addNewObject(std::unique_ptr<TileObject> newObject)
{
    tileSheet->onTileObjectAdded(*newObject);
    objects.insert(objects.end(), std::move(newObject));
}

void Scene::removeObject(const TileObject * target)
{
    tileSheet->onTileObjectRemoved(*target);
    objects.remove_if([&target](const std::unique_ptr<TileObject>& object){
        return object.get() == target;
    });
}

const TileSheet &Scene::getTileSheet() const
{
    return *tileSheet;
}

Scene::~Scene()
{
    delete tileSheet;
}
