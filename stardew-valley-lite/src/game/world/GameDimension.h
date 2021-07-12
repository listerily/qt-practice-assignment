//
// Created by listerily on 2021/7/5.
//

#ifndef STARDEW_VALLEY_LITE_GAMEDIMENSION_H
#define STARDEW_VALLEY_LITE_GAMEDIMENSION_H

#include <string>
#include <list>
#include <memory>

#include "object/TileObject.h"

class DimMapConfig;
class GameDimension
{
private:
    std::string id;
    std::list<std::unique_ptr<TileObject>> objects;
public:
    explicit GameDimension(const DimMapConfig& config);
    ~GameDimension();

public:
    std::list<std::unique_ptr<TileObject>>& getObjects();
    const std::list<std::unique_ptr<TileObject>>& getObjects() const;
    void tick();
    const std::string& getID() const;
    void addNewObject(std::unique_ptr<TileObject>);
    void removeObject(const TileObject*);
private:
    void initialize(const DimMapConfig&);
};


#endif //STARDEW_VALLEY_LITE_GAMEDIMENSION_H
