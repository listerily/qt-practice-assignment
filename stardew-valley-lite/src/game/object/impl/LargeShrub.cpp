//
// Created by listerily on 2021/7/12.
//

#include "LargeShrub.h"

void LargeShrub::playerInteract(Player &player, ItemInstance *item)
{
    TileObject::playerInteract(player, item);
}

LargeShrub::LargeShrub(int x, int y) : TileObject("large_shrub", x, y)
{
    tiles = {
            Tile{{":/svl/textures/tiles/0_13_0.png"}, Tile::WalkableType::ABLE, 0, -2, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_14_0.png"}, Tile::WalkableType::ABLE, 1, -2, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_15_0.png"}, Tile::WalkableType::ABLE, 2, -2, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_13_1.png"}, Tile::WalkableType::ABLE, 0, -1, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_14_1.png"}, Tile::WalkableType::ABLE, 1, -1, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_15_1.png"}, Tile::WalkableType::ABLE, 2, -1, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_13_2.png"}, Tile::WalkableType::DISABLE, 0, 0, Tile::DisplayPriority::ON_GROUND},
            Tile{{":/svl/textures/tiles/0_14_2.png"}, Tile::WalkableType::DISABLE, 1, 0, Tile::DisplayPriority::ON_GROUND},
            Tile{{":/svl/textures/tiles/0_15_2.png"}, Tile::WalkableType::DISABLE, 2, 0, Tile::DisplayPriority::ON_GROUND},
    };
}
