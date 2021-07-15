//
// Created by listerily on 2021/7/15.
//

#include "BedObject.h"

BedObject::BedObject(int x, int y) : TileObject("bed", x, y)
{
    tiles = {
            {{":/svl/textures/house/6_8_7.png"}, Tile::WalkableType::ABLE, 0, -1, Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_9_7.png"}, Tile::WalkableType::ABLE, 1, -1, Tile::DisplayPriority::SKY},
            {{":/svl/textures/house/6_8_8.png"}, Tile::WalkableType::DISABLE, 0, 0, Tile::DisplayPriority::ON_GROUND},
            {{":/svl/textures/house/6_9_8.png"}, Tile::WalkableType::DISABLE, 1, 0, Tile::DisplayPriority::ON_GROUND},
            {{":/svl/textures/house/6_8_9.png"}, Tile::WalkableType::DISABLE, 0, +1, Tile::DisplayPriority::ON_GROUND},
            {{":/svl/textures/house/6_9_9.png"}, Tile::WalkableType::DISABLE, 1, +1, Tile::DisplayPriority::ON_GROUND},
            {{":/svl/textures/house/6_8_10.png"}, Tile::WalkableType::DISABLE, 0, +2, Tile::DisplayPriority::ON_GROUND},
            {{":/svl/textures/house/6_9_10.png"}, Tile::WalkableType::DISABLE, 1, +2, Tile::DisplayPriority::ON_GROUND},
    };
}

bool BedObject::ableToInteract() const
{
    return true;
}

void BedObject::playerInteract(GameWorld &world, ItemInstance *instance, Player &player, Scene &scene, int y, int x)
{
    TileObject::playerInteract(world, instance, player, scene, y, x);

    world.triggerEvent(WorldEvent::SLEEP);
}
