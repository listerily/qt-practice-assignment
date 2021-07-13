//
// Created by listerily on 2021/7/6.
//

#ifndef STARDEW_VALLEY_LITE_GAMEPAINTER_H
#define STARDEW_VALLEY_LITE_GAMEPAINTER_H

class GameWorld;
class QWidget;
class TileObject;
class GamePainter
{
private:
    const GameWorld& gameWorld;
    unsigned long long paintFrameCount = 0;
    int displayBlocksNum;
public:
    explicit GamePainter(const GameWorld& world);
public:
    void paint(QWidget& widget, int width, int height);
    void zoom(int);
};


#endif //STARDEW_VALLEY_LITE_GAMEPAINTER_H
