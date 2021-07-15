//
// Created by listerily on 2021/7/14.
//

#include "AppleTreeObject.h"

AppleTreeObject::AppleTreeObject(int x, int y) : TileObject("apple_tree", x, y)
{
    tiles = {
            Tile{{":/svl/textures/tiles/0_3_0.png"}, Tile::WalkableType::ABLE, -1, -5, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_4_0.png"}, Tile::WalkableType::ABLE, 0, -5, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_5_0.png"}, Tile::WalkableType::ABLE, 1, -5, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_3_1.png"}, Tile::WalkableType::ABLE, -1, -4, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_4_1.png"}, Tile::WalkableType::ABLE, 0, -4, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_5_1.png"}, Tile::WalkableType::ABLE, 1, -4, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_3_2.png"}, Tile::WalkableType::ABLE, -1, -3, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_4_2.png"}, Tile::WalkableType::ABLE, 0, -3, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_5_2.png"}, Tile::WalkableType::ABLE, 1, -3, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_3_3.png"}, Tile::WalkableType::ABLE, -1, -2, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_4_3.png"}, Tile::WalkableType::ABLE, 0, -2, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_5_3.png"}, Tile::WalkableType::ABLE, 1, -2, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_4_4.png"}, Tile::WalkableType::ABLE, 0, -1, Tile::DisplayPriority::SKY},
            Tile{{":/svl/textures/tiles/0_4_5.png"}, Tile::WalkableType::DISABLE, 0, 0, Tile::DisplayPriority::ON_GROUND},
    };
}
