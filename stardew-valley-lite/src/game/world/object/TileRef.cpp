//
// Created by listerily on 2021/7/12.
//

#include "TileRef.h"

#include "Tile.h"

TileRef::TileRef(const Tile * tile) : tile(tile)
{

}

TileRef::TileRef(const Tile & tile) : tile(&tile)
{

}

const Tile &TileRef::operator()() const
{
    return *tile;
}

bool TileRef::operator<(const TileRef & rhs) const
{
    if(tile->displayPriority != rhs.tile->displayPriority)
        return tile->displayPriority < rhs.tile->displayPriority;
    return tile < rhs.tile;
}

bool TileRef::operator>(const TileRef & rhs) const
{
    if(tile->displayPriority != rhs.tile->displayPriority)
        return tile->displayPriority > rhs.tile->displayPriority;
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
