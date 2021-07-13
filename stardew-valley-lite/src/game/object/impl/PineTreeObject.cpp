//
// Created by listerily on 2021/7/13.
//

#include "PineTreeObject.h"

void PineTreeObject::playerInteract(Player &player, ItemInstance &item)
{
    TileObject::playerInteract(player, item);
}

bool PineTreeObject::walkable(int x, int y) const
{
    return x != positionX || y != positionY;
}

PineTreeObject::PineTreeObject(int x, int y) : TileObject("oak_tree", x, y)
{
    tiles = {
            Tile{{":/svl/textures/tiles/0_10_0.png"}, false, -1, -5, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_11_0.png"}, false, 0, -5, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_12_0.png"}, false, 1, -5, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_10_1.png"}, false, -1, -4, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_11_1.png"}, false, 0, -4, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_12_1.png"}, false, 1, -4, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_10_2.png"}, false, -1, -3, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_11_2.png"}, false, 0, -3, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_12_2.png"}, false, 1, -3, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_10_3.png"}, false, -1, -2, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_11_3.png"}, false, 0, -2, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_12_3.png"}, false, 1, -2, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_11_4.png"}, false, 0, -1, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_11_5.png"}, true, 0, 0, Tile::DisplayPriority::ON_GROUND},
    };
}
