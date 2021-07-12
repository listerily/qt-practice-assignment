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

void GamePainter::paint(QWidget& widget, int width, int height)
{
    ++paintFrameCount;
    const int displayBlocksNum = 140;
    const auto& currentDimension = gameWorld.getCurrentGameDimension();
    const auto& player = gameWorld.getPlayer();
    const auto& tileSheet = currentDimension.getTileSheet();
    const auto pixelsCount = width * height;
    const auto displayBlockArea = (double)pixelsCount / displayBlocksNum;
    const auto displayBlockWidth = static_cast<int>(sqrt(displayBlockArea));
    const auto playerPositionX = player.getPosition().first;
    const auto playerPositionY = player.getPosition().second;
    const auto viewPortCenterX = width / 2.0 - (playerPositionX - floor(playerPositionX)) * displayBlockWidth;
    const auto viewPortCenterY = height / 2.0 - (playerPositionY - floor(playerPositionY)) * displayBlockWidth;
    const auto viewPortCenterTargetWorldPointX = (int)floor(playerPositionX);
    const auto viewPortCenterTargetWorldPointY = (int)floor(playerPositionY);
    const auto halfDisplayCountInWidth = (int)ceil(width / 2.0 / displayBlockWidth);
    const auto halfDisplayCountInHeight = (int)ceil(height / 2.0 / displayBlockWidth);
    const auto viewPortStartPointX = viewPortCenterX - displayBlockWidth * halfDisplayCountInWidth;
    const auto viewPortStartPointY = viewPortCenterY - displayBlockWidth * halfDisplayCountInHeight;
    const auto worldStartPointX = viewPortCenterTargetWorldPointX - halfDisplayCountInWidth;
    const auto worldStartPointY = viewPortCenterTargetWorldPointY - halfDisplayCountInHeight;

    QPainter painter(&widget);
    QPen pen;
    for (int currentDrawX = static_cast<int>(viewPortStartPointX), x = worldStartPointX;
         currentDrawX <= width;
         currentDrawX += displayBlockWidth, ++x)
    {
        for(int currentDrawY = static_cast<int>(viewPortStartPointY), y = worldStartPointY;
            currentDrawY <= height;
            currentDrawY += displayBlockWidth, ++y)
        {
            const auto& tileObjects = tileSheet.getTilesAt(x, y);
            for(const auto& tileRef : tileObjects)
            {
                const QRect drawArea(currentDrawX, currentDrawY, displayBlockWidth, displayBlockWidth);
                const auto& textures = tileRef.tile->textures;
                const auto texturesSize = textures.size();
                painter.drawPixmap(drawArea, QPixmap(textures[(paintFrameCount / 30) % texturesSize].c_str()));
            }
        }
    }
    pen.setColor(Qt::black);
    painter.setPen(pen);
    painter.drawRect(QRect{width / 2 - 5, height / 2 - 5, 10, 10});

}
