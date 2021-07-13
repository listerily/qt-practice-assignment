//
// Created by listerily on 2021/7/12.
//

#ifndef STARDEW_VALLEY_LITE_TILEREF_H
#define STARDEW_VALLEY_LITE_TILEREF_H


class Tile;
class TileObject;
class TileRef
{
private:
    int y;
public:
    const Tile* tile;

    TileRef(const Tile&, const TileObject&);
    const Tile& operator()()const;
    bool operator<(const TileRef&) const;
    bool operator>(const TileRef&) const;
    bool operator==(const TileRef&) const;
    bool operator!=(const TileRef&) const;
};


#endif //STARDEW_VALLEY_LITE_TILEREF_H
