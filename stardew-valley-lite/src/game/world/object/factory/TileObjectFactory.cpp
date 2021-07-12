//
// Created by listerily on 2021/7/11.
//

#include "TileObjectFactory.h"

#include <string>
#include <memory>

#include "../impl/PathLand.h"

std::unique_ptr<TileObject> TileObjectFactory::generateTileObjectByIdAt(std::string const& id, int x, int y)
{
    if(id == "path")
        return std::make_unique<PathLand>(x, y);
    return std::make_unique<PathLand>(x, y);
}
