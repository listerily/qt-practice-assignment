//
// Created by listerily on 2021/7/6.
//

#ifndef STARDEW_VALLEY_LITE_OBJECTTILE_H
#define STARDEW_VALLEY_LITE_OBJECTTILE_H


class Tile;
class ObjectTile
{
public:
    enum class DisplayPriority : int
    {
        UNDERGROUND, SURFACE_BOTTOM, SURFACE_MEDIUM, SURFACE_TOP, SURFACE_OVERLAY, ON_GROUND, FLOATING, SKY
    };

    Tile* targetTile = nullptr;
    bool isSolid = false;
    int offsetX = 0, offsetY = 0;
    DisplayPriority displayPriority = DisplayPriority::UNDERGROUND;
};


#endif //STARDEW_VALLEY_LITE_OBJECTTILE_H
