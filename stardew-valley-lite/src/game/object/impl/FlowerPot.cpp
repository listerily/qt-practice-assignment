//
// Created by listerily on 2021/7/13.
//

#include "FlowerPot.h"

FlowerPot::FlowerPot(int x, int y, int aux) : TileObject("flower_pot", x, y)
{
    tiles = {
            Tile{{aux == 0 ? ":/svl/textures/tiles/0_23_43.png" : ":/svl/textures/tiles/0_23_44.png"}, Tile::WalkableType::DISABLE, 0, 0, Tile::DisplayPriority::ON_GROUND}
    };
}