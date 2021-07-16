//
// Created by listerily on 2021/7/15.
//

#include "HomeStairsObject.h"

HomeStairsObject::HomeStairsObject(int x, int y) : TileObject("home_stairs", x, y)
{
    tiles = {
            {{":/svl/textures/house/6_1_15.png"}, Tile::WalkableType::DISABLE, 0, 0, Tile::DisplayPriority::ON_GROUND}
    };
}

bool HomeStairsObject::ableToInteract() const
{
    return true;
}

std::unique_ptr<Action>
HomeStairsObject::interact(GameWorld &world, ItemInstance *instance, Player &p, Scene &scene, int x, int y)
{
    TileObject::interact(world, instance, p, scene, x, y);

    world.changeScene("farm");
    return nullptr;
}
