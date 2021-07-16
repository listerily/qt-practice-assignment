//
// Created by listerily on 2021/7/13.
//

#include "GrassFlowerObject.h"

GrassFlowerObject::GrassFlowerObject(int x, int y) : TileObject("grass_flower", x, y)
{
    tiles = {
            {{":/svl/textures/tiles/0_1_6.png", ":/svl/textures/tiles/0_1_6.png", ":/svl/textures/tiles/0_2_6.png", ":/svl/textures/tiles/0_2_6.png"},
                    Tile::WalkableType::ABLE, 0, 0, Tile::DisplayPriority::SURFACE_BOTTOM}
    };
}
