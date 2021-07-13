//
// Created by listerily on 2021/7/12.
//

#include "TileRef.h"

#include "Tile.h"
#include "TileObject.h"

TileRef::TileRef(const Tile & tile, const TileObject& tileObject) : tile(&tile)
{
    y = tile.offsetY + tileObject.getPosition().second;
}

const Tile &TileRef::operator()() const
{
    return *tile;
}

bool TileRef::operator<(const TileRef & rhs) const
{
    if(tile->displayPriority != rhs.tile->displayPriority)
        return tile->displayPriority < rhs.tile->displayPriority;
    if(y != rhs.y)
        return y < rhs.y;
    return tile < rhs.tile;
}

bool TileRef::operator>(const TileRef & rhs) const
{
    if(tile->displayPriority != rhs.tile->displayPriority)
        return tile->displayPriority > rhs.tile->displayPriority;
    if(y != rhs.y)
        return y > rhs.y;
    return tile > rhs.tile;
}

bool TileRef::operator==(const TileRef & rhs) const
{
    return tile == rhs.tile;
}

bool TileRef::operator!=(const TileRef & rhs) const
{
    return tile != rhs.tile;
}
