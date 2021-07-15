//
// Created by listerily on 2021/7/5.
//

#ifndef STARDEW_VALLEY_LITE_SCENE_H
#define STARDEW_VALLEY_LITE_SCENE_H

#include <string>
#include <list>
#include <memory>

#include "../object/TileObject.h"

class TileSheet;
class SceneMapConfig;
class Scene
{
private:
    std::string id;
    std::list<std::unique_ptr<TileObject>> objects;
    TileSheet* tileSheet;
    double spawnX{}, spawnY{};
public:
    explicit Scene(const SceneMapConfig& config);
    ~Scene();
public:
    std::list<std::unique_ptr<TileObject>>& getObjects();
    const std::list<std::unique_ptr<TileObject>>& getObjects() const;
    void tick();
    const std::string& getID() const;
    void addNewObject(std::unique_ptr<TileObject>);
    void removeObject(TileObject*);
    const TileSheet& getTileSheet() const;
    TileSheet& getTileSheet();
    std::pair<double, double> getSpawn() const;
private:
    void initialize(const SceneMapConfig&);
};


#endif //STARDEW_VALLEY_LITE_SCENE_H
