//
// Created by listerily on 2021/7/6.
//

#ifndef STARDEW_VALLEY_LITE_WORLDPAINTER_H
#define STARDEW_VALLEY_LITE_WORLDPAINTER_H

class GameWorld;
class QWidget;
class TileObject;
class GameClient;
class WorldPainter
{
private:
    unsigned long long paintFrameCount = 0;
    int displayBlocksNum;
public:
    explicit WorldPainter();
public:
    void paint(const GameClient&, const GameWorld &, QWidget& widget, int width, int height);
    void zoom(int);
};


#endif //STARDEW_VALLEY_LITE_WORLDPAINTER_H
