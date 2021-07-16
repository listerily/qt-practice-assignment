//
// Created by listerily on 2021/7/6.
//

#ifndef STARDEW_VALLEY_LITE_WORLDPAINTER_H
#define STARDEW_VALLEY_LITE_WORLDPAINTER_H


class GameWorld;

class QWidget;

class QPainter;

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
    void paint(const GameClient &, const GameWorld &, QWidget &widget, int width, int height);

    void zoom(int);

private:
    void paintWorldGround(QPainter &, const GameClient &, const GameWorld &, QWidget &widget, int width, int height,
                          int viewPortStartPointX, int viewPortStartPointY, int worldStartPointX, int worldStartPointY,
                          int displayBlockWidth) const;

    void paintWorldSky(QPainter &, const GameClient &, const GameWorld &, QWidget &widget, int width, int height,
                       int viewPortStartPointX, int viewPortStartPointY, int worldStartPointX, int worldStartPointY,
                       int displayBlockWidth) const;

    static void
    paintWorldOverlay(QPainter &, const GameClient &, const GameWorld &, QWidget &widget, int width, int height);

    void paintWorldPlayer(QPainter &, const GameClient &, const GameWorld &, QWidget &widget, int width, int height,
                          int displayBlockWidth) const;

    static void
    paintActionBeforePlayer(QPainter &, const GameClient &, const GameWorld &, QWidget &widget, int width, int height,
                            int displayBlockWidth);

    static void
    paintActionAfterPlayer(QPainter &, const GameClient &, const GameWorld &, QWidget &widget, int width, int height,
                           int displayBlockWidth);

    static void
    paintPickupActionBF(QPainter &, const GameClient &, const GameWorld &, QWidget &widget, int width, int height,
                        int displayBlockWidth);

    static void
    paintSmashActionBF(QPainter &, const GameClient &, const GameWorld &, QWidget &widget, int width, int height,
                       int displayBlockWidth);

    static void
    paintPickupActionAF(QPainter &, const GameClient &, const GameWorld &, QWidget &widget, int width, int height,
                        int displayBlockWidth);

    static void
    paintSmashActionAF(QPainter &, const GameClient &, const GameWorld &, QWidget &widget, int width, int height,
                       int displayBlockWidth);
};


#endif //STARDEW_VALLEY_LITE_WORLDPAINTER_H
