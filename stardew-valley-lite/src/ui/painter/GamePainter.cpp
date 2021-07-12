//
// Created by listerily on 2021/7/6.
//

#include "GamePainter.h"

#include <QPainter>
#include <QPen>
#include <QWidget>
#include <cmath>

#include "../../game/world/GameWorld.h"
#include "../../game/world/GameDimension.h"
#include "../../game/world/TileSheet.h"
#include "../../game/entity/Player.h"

GamePainter::GamePainter(const GameWorld &world): gameWorld(world)
{

}
#include <iostream>
void GamePainter::paint(QWidget& widget, int width, int height) const
{
    const int displayBlocksNum = 120;
    const auto& currentDimension = gameWorld.getCurrentGameDimension();
    const auto& player = gameWorld.getPlayer();
    const auto& tileSheet = currentDimension.getTileSheet();
    auto pixelsCount = width * height;
    auto displayBlockArea = (double)pixelsCount / displayBlocksNum;
    auto displayBlockWidth = static_cast<int>(sqrt(displayBlockArea));
    auto playerPositionX = player.getPosition().first;
    auto playerPositionY = player.getPosition().second;
    auto displayStartPointX = fmod((width / 2.0 - (playerPositionX - floor(playerPositionX)) * displayBlockWidth), displayBlockWidth) - displayBlockWidth;
    auto displayStartPointY = fmod((height / 2.0 - (playerPositionY - floor(playerPositionY)) * displayBlockWidth), displayBlockWidth) - displayBlockWidth;
    auto screenWorldStartPointX = (int)playerPositionX - (int)ceil((width / 2.0) / displayBlockWidth);
    auto screenWorldStartPointY = (int)playerPositionY - (int)ceil((height / 2.0) / displayBlockWidth);;

    QPainter painter(&widget);
    QPen pen;
    for (int currentDrawX = static_cast<int>(displayStartPointX), x = screenWorldStartPointX;
         currentDrawX <= width;
         currentDrawX += displayBlockWidth, ++x)
    {
        for(int currentDrawY = static_cast<int>(displayStartPointY), y = screenWorldStartPointY;
            currentDrawY <= height;
            currentDrawY += displayBlockWidth, ++y)
        {
            const auto& tileObjects = tileSheet.getTilesAt(x, y);
            for(const auto& tileRef : tileObjects)
            {
                painter.drawPixmap(QRect(currentDrawX, currentDrawY, displayBlockWidth, displayBlockWidth), QPixmap(":/svl/textures/tiles/0_1_7.png"));
            }
        }
    }
    pen.setColor(Qt::black);
    painter.setPen(pen);
    painter.drawRect(QRect{width / 2 - 5, height / 2 - 5, 10, 10});

}
