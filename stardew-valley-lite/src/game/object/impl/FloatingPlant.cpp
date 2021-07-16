//
// Created by listerily on 2021/7/13.
//

#include "FloatingPlant.h"

FloatingPlant::FloatingPlant(int x, int y, int aux) : TileObject("floating_plant", x, y)
{
    tiles = {
            Tile{aux == 0 ? std::vector<std::string>{":/svl/textures/tiles/0_18_51.png",
                                                     ":/svl/textures/tiles/0_19_51.png",
                                                     ":/svl/textures/tiles/0_20_51.png",
                                                     ":/svl/textures/tiles/0_21_51.png"} :
                 std::vector<std::string>{":/svl/textures/tiles/0_18_52.png", ":/svl/textures/tiles/0_19_52.png",
                                          ":/svl/textures/tiles/0_20_52.png", ":/svl/textures/tiles/0_21_52.png"},
                 Tile::WalkableType::DISABLE, 0, 0, Tile::DisplayPriority::ON_GROUND}
    };
}
