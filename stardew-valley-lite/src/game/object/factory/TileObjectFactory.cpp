//
// Created by listerily on 2021/7/11.
//

#include "TileObjectFactory.h"

#include <string>
#include <memory>
#include <sstream>

#include "../impl/GrassLand.h"
#include "../impl/OakTreeObject.h"
#include "../impl/PineTreeObject.h"
#include "../impl/LargeShrub.h"
#include "../impl/SmallShrub.h"
#include "../impl/WaterObject.h"
#include "../impl/SmallStone.h"
#include "../impl/ManyStones.h"
#include "../impl/PinkFlower.h"
#include "../impl/BlueFlower.h"
#include "../impl/FruitsBarrel.h"
#include "../impl/LilyPad.h"
#include "../impl/WaterStakes.h"
#include "../impl/FloatingPlant.h"
#include "../impl/FlowerPot.h"
#include "../impl/BranchObject.h"
#include "../impl/StoneObject.h"
#include "../impl/WeedsObject.h"
#include "../impl/GrassFlowerObject.h"
#include "../impl/WaterBankObject.h"
#include "../impl/FenceObject.h"
#include "../impl/TentObject.h"
#include "../impl/HouseObject.h"
#include "../impl/TrestleObject.h"
#include "../impl/BorderObject.h"
#include "../impl/AppleTreeObject.h"
#include "../impl/MailBoxObject.h"
#include "../impl/WoodenPlate.h"
#include "../impl/StonePathObject.h"
#include "../impl/AutoMobileObject.h"
#include "../impl/LargeWoodObject.h"
#include "../impl/HouseBackgroundObject.h"
#include "../impl/BedObject.h"
#include "../impl/TVObject.h"
#include "../impl/HomeStairsObject.h"
#include "../impl/HomeBorderObject.h"

std::unique_ptr<TileObject> TileObjectFactory::generateTileObjectByIdAt(std::string const &id, int x, int y)
{
    if (id == "oak_tree")
        return std::make_unique<OakTreeObject>(x, y);
    if (id == "pine_tree")
        return std::make_unique<PineTreeObject>(x, y);
    if (id == "apple_tree")
        return std::make_unique<AppleTreeObject>(x, y);
    if (id == "stone_0")
        return std::make_unique<StoneObject>(x, y, 0);
    if (id == "stone_1")
        return std::make_unique<StoneObject>(x, y, 1);
    if (id == "large_shrub")
        return std::make_unique<LargeShrub>(x, y);
    if (id == "small_shrub")
        return std::make_unique<SmallShrub>(x, y);
    if (id == "water")
        return std::make_unique<WaterObject>(x, y);
    if (id == "small_stone")
        return std::make_unique<SmallStone>(x, y);
    if (id == "many_stones")
        return std::make_unique<ManyStones>(x, y);
    if (id == "pink_flower")
        return std::make_unique<PinkFlower>(x, y);
    if (id == "blue_flower")
        return std::make_unique<BlueFlower>(x, y);
    if (id == "fruits_barrel")
        return std::make_unique<FruitsBarrel>(x, y);
    if (id == "lily_pad_0")
        return std::make_unique<LilyPad>(x, y, 0);
    if (id == "lily_pad_1")
        return std::make_unique<LilyPad>(x, y, 1);
    if (id == "floating_plant_0")
        return std::make_unique<FloatingPlant>(x, y, 0);
    if (id == "floating_plant_1")
        return std::make_unique<FloatingPlant>(x, y, 1);
    if (id == "flower_pot_0")
        return std::make_unique<FlowerPot>(x, y, 0);
    if (id == "flower_pot_1")
        return std::make_unique<FlowerPot>(x, y, 1);
    if (id == "branch_0")
        return std::make_unique<BranchObject>(x, y, 0);
    if (id == "branch_1")
        return std::make_unique<BranchObject>(x, y, 1);
    if (id == "water_stakes")
        return std::make_unique<WaterStakes>(x, y);
    if (id == "weeds_0")
        return std::make_unique<WeedsObject>(x, y, 0);
    if (id == "weeds_1")
        return std::make_unique<WeedsObject>(x, y, 1);
    if (id == "weeds_2")
        return std::make_unique<WeedsObject>(x, y, 2);
    if (id == "weeds_3")
        return std::make_unique<WeedsObject>(x, y, 3);
    if (id == "grass_flower")
        return std::make_unique<GrassFlowerObject>(x, y);
    if (id == "fence_0_0")
        return std::make_unique<FenceObject>(x, y, true, 0);
    if (id == "fence_0_1")
        return std::make_unique<FenceObject>(x, y, true, 1);
    if (id == "fence_0_2")
        return std::make_unique<FenceObject>(x, y, true, 2);
    if (id == "fence_0_3")
        return std::make_unique<FenceObject>(x, y, true, 3);
    if (id == "fence_1_0")
        return std::make_unique<FenceObject>(x, y, false, 0);
    if (id == "fence_1_1")
        return std::make_unique<FenceObject>(x, y, false, 1);
    if (id == "fence_1_2")
        return std::make_unique<FenceObject>(x, y, false, 2);
    if (id == "tent")
        return std::make_unique<TentObject>(x, y);
    if (id == "mail_box")
        return std::make_unique<MailBoxObject>(x, y);
    if (id == "house")
        return std::make_unique<HouseObject>(x, y);
    if (id == "trestle_0")
        return std::make_unique<TrestleObject>(x, y, 0);
    if (id == "trestle_1")
        return std::make_unique<TrestleObject>(x, y, 1);
    if (id == "trestle_2")
        return std::make_unique<TrestleObject>(x, y, 2);
    if (id == "stone_path_0")
        return std::make_unique<StonePathObject>(x, y, 0);
    if (id == "stone_path_1")
        return std::make_unique<StonePathObject>(x, y, 1);
    if (id == "stone_path_2")
        return std::make_unique<StonePathObject>(x, y, 2);
    if (id == "automobile")
        return std::make_unique<AutoMobileObject>(x, y);
    if (id == "large_wood_0")
        return std::make_unique<LargeWoodObject>(x, y, 0);
    if (id == "large_wood_1")
        return std::make_unique<LargeWoodObject>(x, y, 1);
    if (id == "house_background")
        return std::make_unique<HouseBackgroundObject>(x, y);
    if (id == "bed")
        return std::make_unique<BedObject>(x, y);
    if (id == "tv")
        return std::make_unique<TVObject>(x, y);
    if (id == "home_stairs")
        return std::make_unique<HomeStairsObject>(x, y);
    if (id == "home_border")
        return std::make_unique<HomeBorderObject>(x, y);

    for (int i = 0; i < 4; ++i)
    {
        std::stringstream stream;
        stream << "wooden_plate_" << i;
        if (id == stream.str())
            return std::make_unique<WoodenPlate>(x, y, i);
    }

    for (int i = 0; i < 11; ++i)
    {
        std::stringstream stream;
        stream << "border_" << i;
        if (id == stream.str())
            return std::make_unique<BorderObject>(x, y, i);
    }

    for (int i = 0; i < 16; ++i)
    {
        std::stringstream stream;
        stream << "bank_" << i;
        if (id == stream.str())
            return std::make_unique<WaterBankObject>(x, y, i);
    }

    for (int i = 0; i < 32; ++i)
    {
        std::stringstream stream;
        stream << "grass_" << i;
        if (id == stream.str())
            return std::make_unique<GrassLand>(x, y, i);
    }

    return std::make_unique<BorderObject>(x, y, 8);
}
