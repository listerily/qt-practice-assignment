//
// Created by listerily on 2021/7/12.
//

#include "OakTreeObject.h"

void OakTreeObject::playerInteract(Player &player, ItemInstance &item)
{
    TileObject::playerInteract(player, item);
}

bool OakTreeObject::walkable(int x, int y) const
{
    return x != positionX || y != positionY;
}

OakTreeObject::OakTreeObject(int x, int y) : TileObject("oak_tree", x, y)
{
    tiles = {
        Tile{{":/svl/textures/tiles/0_0_0.png"}, false, -1, -5, Tile::DisplayPriority::SKY},
        Tile{{":/svl/textures/tiles/0_1_0.png"}, false, 0, -5, Tile::DisplayPriority::SKY},
        Tile{{":/svl/textures/tiles/0_2_0.png"}, false, 1, -5, Tile::DisplayPriority::SKY},
        Tile{{":/svl/textures/tiles/0_0_1.png"}, false, -1, -4, Tile::DisplayPriority::SKY},
        Tile{{":/svl/textures/tiles/0_1_1.png"}, false, 0, -4, Tile::DisplayPriority::SKY},
        Tile{{":/svl/textures/tiles/0_2_1.png"}, false, 1, -4, Tile::DisplayPriority::SKY},
        Tile{{":/svl/textures/tiles/0_0_2.png"}, false, -1, -3, Tile::DisplayPriority::SKY},
        Tile{{":/svl/textures/tiles/0_1_2.png"}, false, 0, -3, Tile::DisplayPriority::SKY},
        Tile{{":/svl/textures/tiles/0_2_2.png"}, false, 1, -3, Tile::DisplayPriority::SKY},
        Tile{{":/svl/textures/tiles/0_0_3.png"}, false, -1, -2, Tile::DisplayPriority::SKY},
        Tile{{":/svl/textures/tiles/0_1_3.png"}, false, 0, -2, Tile::DisplayPriority::SKY},
        Tile{{":/svl/textures/tiles/0_2_3.png"}, false, 1, -2, Tile::DisplayPriority::SKY},
        Tile{{":/svl/textures/tiles/0_1_4.png"}, false, 0, -1, Tile::DisplayPriority::SKY},
        Tile{{":/svl/textures/tiles/0_1_5.png"}, true, 0, 0, Tile::DisplayPriority::ON_GROUND},
    };
}
