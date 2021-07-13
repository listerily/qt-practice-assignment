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
        template <class T1, class T2>
        std::size_t operator() (const std::pair<T1, T2> &pair) const {
            return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
        }
    };

    std::unordered_map<std::pair<int, int>, std::set<const TileObject*>, pair_hash> lookup;
    std::unordered_map<std::pair<int, int>, std::set<TileRef>, pair_hash> lookupTiles;
public:
    TileSheet() = default;

    void onTileObjectAdded(const TileObject&);
    void onTileObjectChanged(const TileObject&);
    void onTileObjectRemoved(const TileObject&);

    const std::set<const TileObject*>& getTileObjectsAt(int, int) const;
    const std::set<TileRef> & getTilesAt(int, int) const;
private:
    void removeTileObjectInLookup(const TileObject&);
    void addTileObjectInLookup(const TileObject&);
};

#endif //STARDEW_VALLEY_LITE_TILESHEET_H
