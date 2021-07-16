//
// Created by listerily on 2021/7/13.
//

#include "PineTreeObject.h"


PineTreeObject::PineTreeObject(int x, int y) : TreeObject("oak_tree", x, y)
{
    tiles = {
            Tile{{":/svl/textures/tiles/0_10_0.png"}, Tile::WalkableType::ABLE, -1, -5, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_11_0.png"}, Tile::WalkableType::ABLE, 0, -5, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_12_0.png"}, Tile::WalkableType::ABLE, 1, -5, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_10_1.png"}, Tile::WalkableType::ABLE, -1, -4, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_11_1.png"}, Tile::WalkableType::ABLE, 0, -4, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_12_1.png"}, Tile::WalkableType::ABLE, 1, -4, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_10_2.png"}, Tile::WalkableType::ABLE, -1, -3, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_11_2.png"}, Tile::WalkableType::ABLE, 0, -3, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_12_2.png"}, Tile::WalkableType::ABLE, 1, -3, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_10_3.png"}, Tile::WalkableType::ABLE, -1, -2, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_11_3.png"}, Tile::WalkableType::ABLE, 0, -2, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_12_3.png"}, Tile::WalkableType::ABLE, 1, -2, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_11_4.png"}, Tile::WalkableType::ABLE, 0, -1, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_11_5.png"}, Tile::WalkableType::DISABLE, 0, 0,
                 Tile::DisplayPriority::ON_GROUND},
    };
}
