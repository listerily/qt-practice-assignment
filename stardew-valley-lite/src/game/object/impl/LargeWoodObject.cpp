//
// Created by listerily on 2021/7/14.
//

#include "LargeWoodObject.h"

LargeWoodObject::LargeWoodObject(int x, int y, int type) : TileObject("large_wood", x, y)
{
    if(type == 0)
    {
        tiles = {
                {{":/svl/textures/items/4_0_26.png"}, Tile::WalkableType::DISABLE, 0, -1, Tile::DisplayPriority::ON_GROUND},
                {{":/svl/textures/items/4_1_26.png"}, Tile::WalkableType::DISABLE, 1, -1, Tile::DisplayPriority::ON_GROUND},
                {{":/svl/textures/items/4_0_27.png"}, Tile::WalkableType::DISABLE, 0, 0, Tile::DisplayPriority::ON_GROUND},
                {{":/svl/textures/items/4_1_27.png"}, Tile::WalkableType::DISABLE, 1, 0, Tile::DisplayPriority::ON_GROUND},
        };
    }
    else if(type == 1)
    {
        tiles = {
                {{":/svl/textures/items/4_2_26.png"}, Tile::WalkableType::DISABLE, 0, -1, Tile::DisplayPriority::ON_GROUND},
                {{":/svl/textures/items/4_3_26.png"}, Tile::WalkableType::DISABLE, 1, -1, Tile::DisplayPriority::ON_GROUND},
                {{":/svl/textures/items/4_2_27.png"}, Tile::WalkableType::DISABLE, 0, 0, Tile::DisplayPriority::ON_GROUND},
                {{":/svl/textures/items/4_3_27.png"}, Tile::WalkableType::DISABLE, 1, 0, Tile::DisplayPriority::ON_GROUND},
        };
    }
}
