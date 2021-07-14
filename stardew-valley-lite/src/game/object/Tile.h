//
// Created by listerily on 2021/7/6.
//

#ifndef STARDEW_VALLEY_LITE_TILE_H
#define STARDEW_VALLEY_LITE_TILE_H

#include <string>
#include <vector>
class Tile;
class Tile
{
public:
    enum class DisplayPriority : int
    {
        UNDERGROUND, SURFACE_BOTTOM, SURFACE_MEDIUM, SURFACE_TOP, SURFACE_OVERLAY, ON_GROUND, FLOATING, SKY
    };

    enum class WalkableType : int
    {
        FORCED_DISABLE, DISABLE, ABLE, FORCED_ABLE
    };

    std::vector<std::string> textures;
    WalkableType walkable = WalkableType::ABLE;
    int offsetX = 0, offsetY = 0;
    DisplayPriority displayPriority = DisplayPriority::UNDERGROUND;
};


#endif //STARDEW_VALLEY_LITE_TILE_H
