//
// Created by listerily on 2021/7/12.
//

#include "SmallShrub.h"

SmallShrub::SmallShrub(int x, int y) : TileObject("small_shrub", x, y)
{
    tiles = {
            Tile{{":/svl/textures/tiles/0_13_3.png"}, false, 0, -1, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_14_3.png"}, false, 1, -1, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_13_4.png"}, false, 0, 0, Tile::DisplayPriority::ON_GROUND},
            Tile{{":/svl/textures/tiles/0_14_4.png"}, false, 1, 0, Tile::DisplayPriority::ON_GROUND},
            };
}

void SmallShrub::playerInteract(Player &player, Item &item, int x, int y)
{
    TileObject::playerInteract(player, item, x, y);
}

bool SmallShrub::walkable(int x, int y) const
{
    return !((x == positionX && y == positionY) ||
           (x == positionX + 1 && y == positionY));
}
