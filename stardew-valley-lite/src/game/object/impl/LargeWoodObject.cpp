//
// Created by listerily on 2021/7/14.
//

#include "LargeWoodObject.h"

#include "../../action/SmashAndGetAction.h"

LargeWoodObject::LargeWoodObject(int x, int y, int type) : TileObject("large_wood", x, y)
{
    life = 10;
    if (type == 0)
    {
        tiles = {
                {{":/svl/textures/items/4_0_25.png"}, Tile::WalkableType::DISABLE, 0, -1, Tile::DisplayPriority::ON_GROUND},
                {{":/svl/textures/items/4_1_25.png"}, Tile::WalkableType::DISABLE, 1, -1, Tile::DisplayPriority::ON_GROUND},
                {{":/svl/textures/items/4_0_26.png"}, Tile::WalkableType::DISABLE, 0, 0,  Tile::DisplayPriority::ON_GROUND},
                {{":/svl/textures/items/4_1_26.png"}, Tile::WalkableType::DISABLE, 1, 0,  Tile::DisplayPriority::ON_GROUND},
        };
    } else if (type == 1)
    {
        tiles = {
                {{":/svl/textures/items/4_2_25.png"}, Tile::WalkableType::DISABLE, 0, -1, Tile::DisplayPriority::ON_GROUND},
                {{":/svl/textures/items/4_3_25.png"}, Tile::WalkableType::DISABLE, 1, -1, Tile::DisplayPriority::ON_GROUND},
                {{":/svl/textures/items/4_2_26.png"}, Tile::WalkableType::DISABLE, 0, 0,  Tile::DisplayPriority::ON_GROUND},
                {{":/svl/textures/items/4_3_26.png"}, Tile::WalkableType::DISABLE, 1, 0,  Tile::DisplayPriority::ON_GROUND},
        };
    }
}

bool LargeWoodObject::ableToInteract() const
{
    return true;
}

std::unique_ptr<Action>
LargeWoodObject::interact(GameWorld &world, ItemInstance *instance, Player &player, Scene &scene, int x, int y)
{
    if (life > 0 && instance && instance->itemMatches(ItemInstance("axe")))
    {
        --life;
        if (life == 0)
            return std::make_unique<SmashAndGetAction>(*instance->getItem(), ItemInstance("wood", 10), *this, true);
        return std::make_unique<SmashAndGetAction>(*instance->getItem(), ItemInstance("wood", 0), *this, false);
    }
    return TileObject::interact(world, instance, player, scene, x, y);
}
