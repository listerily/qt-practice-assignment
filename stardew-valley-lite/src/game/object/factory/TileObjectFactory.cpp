//
// Created by listerily on 2021/7/11.
//

#include "TileObjectFactory.h"

#include <string>
#include <memory>

#include "src/game/object/impl/PathLand.h"
#include "src/game/object/impl/GrassLand.h"
#include "src/game/object/impl/OakTreeObject.h"
#include "src/game/object/impl/PineTreeObject.h"
#include "src/game/object/impl/LargeShrub.h"
#include "src/game/object/impl/SmallShrub.h"
#include "src/game/object/impl/WaterObject.h"
#include "src/game/object/impl/SmallStone.h"
#include "src/game/object/impl/ManyStones.h"
#include "src/game/object/impl/PinkFlower.h"
#include "src/game/object/impl/BlueFlower.h"
#include "src/game/object/impl/FruitsBarrel.h"
#include "src/game/object/impl/LilyPad.h"
#include "src/game/object/impl/WaterStakes.h"
#include "src/game/object/impl/FloatingPlant.h"
#include "src/game/object/impl/FlowerPot.h"
#include "src/game/object/impl/BranchObject.h"
#include "src/game/object/impl/StoneObject.h"
#include "src/game/object/impl/WeedsObject.h"

std::unique_ptr<TileObject> TileObjectFactory::generateTileObjectByIdAt(std::string const& id, int x, int y)
{
    if(id == "oak_tree")
        return std::make_unique<OakTreeObject>(x, y);
    if(id == "pine_tree")
        return std::make_unique<PineTreeObject>(x, y);
    if(id == "stone")
        return std::make_unique<StoneObject>(x, y);
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
    if(id == "fruits_barrel")
        return std::make_unique<FruitsBarrel>(x, y);
    if(id == "lily_pad_0")
        return std::make_unique<LilyPad>(x, y, 0);
    if(id == "lily_pad_1")
        return std::make_unique<LilyPad>(x, y, 1);
    if(id == "floating_plant_0")
        return std::make_unique<FloatingPlant>(x, y, 0);
    if(id == "floating_plant_1")
        return std::make_unique<FloatingPlant>(x, y, 1);
    if(id == "flower_pot_0")
        return std::make_unique<FlowerPot>(x, y, 0);
    if(id == "flower_pot_1")
        return std::make_unique<FlowerPot>(x, y, 1);
    if(id == "branch_0")
        return std::make_unique<BranchObject>(x, y, 0);
    if(id == "branch_1")
        return std::make_unique<BranchObject>(x, y, 1);
    if(id == "water_stakes")
        return std::make_unique<WaterStakes>(x, y);
    if(id == "weeds_0")
        return std::make_unique<WeedsObject>(x, y, 0);
    if(id == "weeds_1")
        return std::make_unique<WeedsObject>(x, y, 1);
    if(id == "weeds_2")
        return std::make_unique<WeedsObject>(x, y, 2);
    if(id == "weeds_3")
        return std::make_unique<WeedsObject>(x, y, 3);

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
