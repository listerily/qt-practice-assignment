//
// Created by listerily on 2021/7/12.
//

#include "LargeShrub.h"

void LargeShrub::playerInteract(Player &player, Item &item, int x, int y)
{
    TileObject::playerInteract(player, item, x, y);
}

bool LargeShrub::walkable(int x, int y) const
{
    return !((x == positionX && y == positionY) ||
            (x == positionX + 1 && y == positionY) ||
            (x == positionX + 2 && y == positionY));
}

LargeShrub::LargeShrub(int x, int y) : TileObject("large_shrub", x, y)
{
    tiles = {
            Tile{{":/svl/textures/tiles/0_13_0.png"}, false, 0, -2, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_14_0.png"}, false, 1, -2, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_15_0.png"}, false, 2, -2, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_13_1.png"}, false, 0, -1, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_14_1.png"}, false, 1, -1, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_15_1.png"}, false, 2, -1, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_13_2.png"}, true, 0, 0, Tile::DisplayPriority::ON_GROUND},
            Tile{{":/svl/textures/tiles/0_14_2.png"}, true, 1, 0, Tile::DisplayPriority::ON_GROUND},
            Tile{{":/svl/textures/tiles/0_15_2.png"}, true, 2, 0, Tile::DisplayPriority::ON_GROUND},
    };
}
