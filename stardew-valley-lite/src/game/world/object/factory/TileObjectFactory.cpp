//
// Created by listerily on 2021/7/11.
//

#include "TileObjectFactory.h"

#include <string>
#include <memory>

#include "../impl/PathLand.h"
#include "../impl/GrassLand.h"
#include "../impl/OakTreeObject.h"
#include "../impl/LargeShrub.h"
#include "../impl/SmallShrub.h"
#include "../impl/WaterObject.h"
#include "../impl/SmallStone.h"
#include "../impl/ManyStones.h"
#include "../impl/PinkFlower.h"
#include "../impl/BlueFlower.h"

std::unique_ptr<TileObject> TileObjectFactory::generateTileObjectByIdAt(std::string const& id, int x, int y)
{
    if(id == "oak_tree")
        return std::make_unique<OakTreeObject>(x, y);
    if(id == "large_shrub")
        return std::make_unique<LargeShrub>(x, y);
    if(id == "small_shrub")
        return std::make_unique<SmallShrub>(x, y);
    if(id == "water")
        return std::make_unique<WaterObject>(x, y);
    if(id == "small_stone")
        return std::make_unique<SmallStone>(x, y);
    if(id == "many_stones")
        return std::make_unique<ManyStones>(x, y);
    if(id == "pink_flower")
        return std::make_unique<PinkFlower>(x, y);
    if(id == "blue_flower")
        return std::make_unique<BlueFlower>(x, y);

    if(id == "path_0")
        return std::make_unique<PathLand>(x, y, 0);

    if(id == "grass_0")
        return std::make_unique<GrassLand>(x, y, 0);
    if(id == "grass_1")
        return std::make_unique<GrassLand>(x, y, 1);
    if(id == "grass_2")
        return std::make_unique<GrassLand>(x, y, 2);
    if(id == "grass_3")
        return std::make_unique<GrassLand>(x, y, 3);


    return std::make_unique<PathLand>(x, y, 0);
}
