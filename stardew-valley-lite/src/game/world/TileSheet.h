//
// Created by listerily on 2021/7/12.
//

#ifndef STARDEW_VALLEY_LITE_TILESHEET_H
#define STARDEW_VALLEY_LITE_TILESHEET_H

#include <set>
#include <unordered_map>
#include <vector>

#include "../object/TileRef.h"

class TileObject;

class Tile;

class TileSheet
{
private:
    struct pair_hash
    {
        template<class T1, class T2>
        std::size_t operator()(const std::pair<T1, T2> &pair) const
        {
            return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
        }
    };

    std::unordered_map<std::pair<int, int>, std::set<TileObject *>, pair_hash> lookupAt;
    std::unordered_map<std::pair<int, int>, std::set<TileRef>, pair_hash> lookupTiles;
    std::unordered_map<std::pair<int, int>, std::set<std::pair<TileRef, TileObject *>>, pair_hash> lookupCovered;
public:
    TileSheet() = default;

    void addTileObject(TileObject &);

    void changeTileObject(TileObject &);

    void removeTileObject(TileObject &);

    const std::set<std::pair<TileRef, TileObject *>> &getTilesAndObjectsCoveredAt(int, int) const;

    const std::set<TileRef> &getTilesAt(int, int) const;

    const std::set<TileObject *> &getTileObjectsAt(int, int) const;

private:
    void removeTileObjectInLookup(TileObject &);

    void addTileObjectInLookup(TileObject &);
};

#endif //STARDEW_VALLEY_LITE_TILESHEET_H
