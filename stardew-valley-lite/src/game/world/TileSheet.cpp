//
// Created by listerily on 2021/7/12.
//

#include "TileSheet.h"

#include "../object/TileObject.h"

void TileSheet::addTileObject(TileObject & object)
{
    addTileObjectInLookup(object);
}

void TileSheet::changeTileObject(TileObject & object)
{
    removeTileObjectInLookup(object);
    addTileObjectInLookup(object);
}

void TileSheet::removeTileObject(TileObject & object)
{
    removeTileObjectInLookup(object);
}

const std::set<TileObject *>& TileSheet::getTileObjectsCoveredAt(int x, int y) const
{
    static const std::set<TileObject *> emptyReturn;
    if(lookupCovered.find({x, y}) == lookupCovered.end())
        return emptyReturn;
    return lookupCovered.at({x, y});
}

void TileSheet::removeTileObjectInLookup(TileObject & target)
{
    lookupAt[target.getPosition()].erase(&target);
    const auto& allTiles = target.getAllTiles();
    for(const auto& tile : allTiles)
    {
        const auto& posX = target.getPosition().first + tile.offsetX;
        const auto& posY = target.getPosition().second + tile.offsetY;
        lookupCovered[{posX, posY}].erase(&target);

        lookupTiles[{posX, posY}].erase(TileRef(tile, target));
    }
}

void TileSheet::addTileObjectInLookup(TileObject & target)
{
    lookupAt[target.getPosition()].insert(&target);
    const auto& allTiles = target.getAllTiles();
    for(const auto& tile : allTiles)
    {
        const auto& posX = target.getPosition().first + tile.offsetX;
        const auto& posY = target.getPosition().second + tile.offsetY;
        lookupCovered[{posX, posY}].insert(&target);

        lookupTiles[{posX, posY}].insert(TileRef(tile, target));
    }
}

const std::set<TileRef>& TileSheet::getTilesAt(int x, int y) const
{
    static const std::set<TileRef> emptyReturn;
    if(lookupTiles.find({x, y}) == lookupTiles.end())
        return emptyReturn;
    return lookupTiles.at({x, y});
}

const std::set<TileObject *> &TileSheet::getTileObjectsAt(int x, int y) const
{
    static const std::set<TileObject*> emptyReturn;
    if(lookupAt.find({x, y}) == lookupAt.end())
        return emptyReturn;
    return lookupAt.at({x, y});
}
