//
// Created by listerily on 2021/7/11.
//

#ifndef STARDEW_VALLEY_LITE_TILEOBJECTFACTORY_H
#define STARDEW_VALLEY_LITE_TILEOBJECTFACTORY_H

#include <memory>

class TileObject;

class TileObjectFactory
{
public:
    static std::unique_ptr<TileObject> generateTileObjectByIdAt(std::string const &id, int x, int y);
};


#endif //STARDEW_VALLEY_LITE_TILEOBJECTFACTORY_H
