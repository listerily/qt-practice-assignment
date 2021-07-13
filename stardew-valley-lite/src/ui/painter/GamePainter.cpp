//
// Created by listerily on 2021/7/6.
//

#include "GamePainter.h"

#include <QPainter>
#include <QPen>
#include <QWidget>
#include <cmath>

#include "../../game/world/GameWorld.h"
#include "../../game/world/Scene.h"
#include "../../game/world/TileSheet.h"
#include "../../game/entity/Player.h"

GamePainter::GamePainter(const GameWorld &world): gameWorld(world)
{

}

void GamePainter::paint(QWidget& widget, int width, int height)
{
    ++paintFrameCount;
    const int displayBlocksNum = 140;
    const auto& currentDimension = gameWorld.getCurrentGameScene();
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
    //paint tiles
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
                if(tileRef().displayPriority <= Tile::DisplayPriority::ON_GROUND)
                {
                    const QRect drawArea(currentDrawX, currentDrawY, displayBlockWidth, displayBlockWidth);
                    const auto& textures = tileRef.tile->textures;
                    const auto texturesSize = textures.size();
                    painter.drawPixmap(drawArea, QPixmap(textures[(paintFrameCount / 30) % texturesSize].c_str()));
                }
            }
        }
    }

    //paint player
    {
        const QRect playerRect(width / 2 - displayBlockWidth / 2, height / 2 - displayBlockWidth * 6 / 5, displayBlockWidth, displayBlockWidth * 3 / 2);

        std::string resID;
        if(player.isMoving())
        {
            const unsigned int selection = (paintFrameCount / 5) % 3;
            switch (player.getFacing())
            {
                case Player::Facing::UP:
                    resID = std::array<std::string, 3>{":/svl/textures/character/2_1_2.png", ":/svl/textures/character/2_2_2.png", ":/svl/textures/character/2_3_2.png"}[selection];
                    break;
                case Player::Facing::DOWN:
                    resID = std::array<std::string, 3>{":/svl/textures/character/2_1_0.png", ":/svl/textures/character/2_2_0.png", ":/svl/textures/character/2_3_0.png"}[selection];
                    break;
                case Player::Facing::LEFT:
                    resID = std::array<std::string, 3>{":/svl/textures/character/2_1_3.png", ":/svl/textures/character/2_2_3.png", ":/svl/textures/character/2_3_3.png"}[selection];
                    break;
                case Player::Facing::RIGHT:
                    resID = std::array<std::string, 3>{":/svl/textures/character/2_1_1.png", ":/svl/textures/character/2_2_1.png", ":/svl/textures/character/2_3_1.png"}[selection];
                    break;
            }
        }
        else
        {
            switch (player.getFacing())
            {
                case Player::Facing::UP:
                    resID = ":/svl/textures/character/2_0_2.png";
                    break;
                case Player::Facing::DOWN:
                    resID = ":/svl/textures/character/2_0_0.png";
                    break;
                case Player::Facing::LEFT:
                    resID = ":/svl/textures/character/2_0_3.png";
                    break;
                case Player::Facing::RIGHT:
                    resID = ":/svl/textures/character/2_0_1.png";
                    break;
            }
        }
        painter.drawPixmap(playerRect, QPixmap(resID.c_str()));
    }

    //paint tiles
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
                if(tileRef().displayPriority == Tile::DisplayPriority::SKY)
                {
                    const QRect drawArea(currentDrawX, currentDrawY, displayBlockWidth, displayBlockWidth);
                    const auto& textures = tileRef.tile->textures;
                    const auto texturesSize = textures.size();
                    painter.drawPixmap(drawArea, QPixmap(textures[(paintFrameCount / 30) % texturesSize].c_str()));
                }
            }
        }
    }
}
