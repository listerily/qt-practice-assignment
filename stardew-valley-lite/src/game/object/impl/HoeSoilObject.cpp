//
// Created by listerily on 2021/7/16.
//

#include "HoeSoilObject.h"

#include "../../object/factory/TileObjectFactory.h"

HoeSoilObject::HoeSoilObject(int x, int y) : TileObject("hoe_soil", x, y)
{
    tiles = {
            {{":/svl/textures/tiles/0_5_27.png"}, Tile::WalkableType::ABLE, 0, 0, Tile::DisplayPriority::SURFACE_TOP}
    };
}

std::unique_ptr<Action>
HoeSoilObject::interact(GameWorld &world, ItemInstance *instance, Player &player, Scene &scene, int x, int y)
{
    if (instance && instance->itemMatches(ItemInstance("mixed_seeds")))
    {
        instance->reduce(1);
        scene.addNewObject(TileObjectFactory::generateTileObjectByIdAt("parsnip", x, y));
    }
    return TileObject::interact(world, instance, player, scene, x, y);
}
