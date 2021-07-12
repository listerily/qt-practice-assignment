//
// Created by listerily on 2021/7/12.
//

#include "TileSheet.h"

#include "object/TileObject.h"

void TileSheet::onTileObjectAdded(const TileObject & object)
{
    addTileObjectInLookup(object);
}

void TileSheet::onTileObjectChanged(const TileObject & object)
{
    removeTileObjectInLookup(object);
    addTileObjectInLookup(object);
}

void TileSheet::onTileObjectRemoved(const TileObject & object)
{
    removeTileObjectInLookup(object);
}

const std::set<const TileObject *>& TileSheet::getTileObjectsAt(int x, int y) const
{
    static const std::set<const TileObject *> emptyReturn;
    if(lookup.find({x, y}) == lookup.end())
        return emptyReturn;
    return lookup.at({x, y});
}

void TileSheet::removeTileObjectInLookup(const TileObject & target)
{
    const auto& allTiles = target.getAllTiles();
    for(const auto& tile : allTiles)
    {
        const auto& posX = tile.offsetX;
        const auto& posY = tile.offsetY;
        lookup[{posX, posY}].erase(&target);

        lookupTiles[{posX, posY}].erase(tile);
    }
}

void TileSheet::addTileObjectInLookup(const TileObject & target)
{
    const auto& allTiles = target.getAllTiles();
    for(const auto& tile : allTiles)
    {
        const auto& posX = tile.offsetX;
        const auto& posY = tile.offsetY;
        lookup[{posX, posY}].insert(&target);

        lookupTiles[{posX, posY}].insert(tile);
    }
}

const std::set<TileRef>& TileSheet::getTilesAt(int x, int y) const
{
    static const std::set<TileRef> emptyReturn;
    if(lookupTiles.find({x, y}) == lookupTiles.end())
        return emptyReturn;
    return lookupTiles.at({x, y});
}
