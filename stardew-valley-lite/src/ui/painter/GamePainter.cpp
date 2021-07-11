//
// Created by listerily on 2021/7/6.
//

#include "GamePainter.h"

#include <QPainter>
#include <QPen>
#include <QWidget>
#include <cmath>

GamePainter::GamePainter(const GameWorld &world): gameWorld(world)
{

}

void GamePainter::paint(QWidget& widget, int width, int height) const
{
    const int displayBlocksNum = 120;
    auto pixelsCount = width * height;
    auto displayBlockArea = (double)pixelsCount / displayBlocksNum;
    auto displayBlockWidth = static_cast<int>(sqrt(displayBlockArea));
    auto playerPositionX = 0.0;
    auto playerPositionY = 0.0;
    auto displayStartPointX = fmod((width / 2.0 - (playerPositionX - floor(playerPositionX)) * displayBlockWidth), displayBlockWidth) - displayBlockWidth;
    auto displayStartPointY = fmod((height / 2.0 - (playerPositionY - floor(playerPositionY)) * displayBlockWidth), displayBlockWidth) - displayBlockWidth;

    QPainter painter(&widget);
    for (int currentDrawX = static_cast<int>(displayStartPointX);
         currentDrawX <= width;
         currentDrawX += displayBlockWidth)
    {
        for(int currentDrawY = static_cast<int>(displayStartPointY);
            currentDrawY <= height;
            currentDrawY += displayBlockWidth)
        {
            painter.drawPixmap(QRect(currentDrawX, currentDrawY, displayBlockWidth, displayBlockWidth), QPixmap(":/svl/textures/tiles/0_1_7.png"));
        }
    }
}
