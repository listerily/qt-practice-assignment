//
// Created by listerily on 2021/7/14.
//

#include "MailBoxObject.h"

MailBoxObject::MailBoxObject(int x, int y) : TileObject("mail_box", x, y)
{
    tiles = {
            {{":/svl/textures/tiles/0_5_78.png"}, Tile::WalkableType::DISABLE, 0, 0,  Tile::DisplayPriority::ON_GROUND},
            {{":/svl/textures/tiles/0_5_77.png"}, Tile::WalkableType::ABLE,    0, -1, Tile::DisplayPriority::SKY}
    };
}
