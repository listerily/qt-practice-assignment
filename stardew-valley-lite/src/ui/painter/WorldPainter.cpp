//
// Created by listerily on 2021/7/6.
//

#include "WorldPainter.h"

#include <QPainter>
#include <QPen>
#include <QWidget>
#include <cmath>
#include <QPainterPath>

#include "../../game/world/GameWorld.h"
#include "../../game/world/Scene.h"
#include "../../game/world/TileSheet.h"
#include "../../game/entity/Player.h"
#include "../../game/world/WorldStatus.h"
#include "../../game/GameClient.h"
#include "../../game/action/PickupAction.h"
#include "../../game/action/SmashAction.h"
#include "../../game/item/Item.h"

WorldPainter::WorldPainter()
{
    displayBlocksNum = 120;
}

void WorldPainter::paint(const GameClient& client, const GameWorld & world, QWidget& widget, int width, int height)
{
    ++paintFrameCount;

    const auto& player = world.getPlayer();
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
    paintWorldGround(painter, client, world, widget, width, height, (int)viewPortStartPointX, (int)viewPortStartPointY, worldStartPointX, worldStartPointY, displayBlockWidth);
    paintActionBeforePlayer(painter, client, world, widget, width, height, displayBlockWidth);
    paintWorldPlayer(painter, client, world, widget, width, height, displayBlockWidth);
    paintActionAfterPlayer(painter, client, world, widget, width, height, displayBlockWidth);
    paintWorldSky(painter, client, world, widget, width, height, (int)viewPortStartPointX, (int)viewPortStartPointY, worldStartPointX, worldStartPointY, displayBlockWidth);
    paintWorldOverlay(painter, client, world, widget, width, height);
}

void WorldPainter::zoom(int delta)
{
    displayBlocksNum += delta;
    if(displayBlocksNum < 80)
        displayBlocksNum = 80;
    if(displayBlocksNum > 240)
        displayBlocksNum = 240;
}

void WorldPainter::paintWorldGround(QPainter& painter, const GameClient & client, const GameWorld & world, QWidget &widget, int width, int height,
                                    int viewPortStartPointX, int viewPortStartPointY, int worldStartPointX,
                                    int worldStartPointY, int displayBlockWidth) const
{
    const auto& currentDimension = world.getCurrentGameScene();
    const auto& player = world.getPlayer();
    const auto& tileSheet = currentDimension.getTileSheet();
    for (int currentDrawX = viewPortStartPointX, x = worldStartPointX;
         currentDrawX <= width;
         currentDrawX += displayBlockWidth, ++x)
    {
        for(int currentDrawY = viewPortStartPointY, y = worldStartPointY;
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
                    painter.drawPixmap(drawArea, QPixmap(textures[(paintFrameCount / 25) % texturesSize].c_str()));
                }
            }
        }
    }
}

void WorldPainter::paintWorldSky(QPainter& painter, const GameClient & client, const GameWorld & world, QWidget &widget, int width, int height,
                                    int viewPortStartPointX, int viewPortStartPointY, int worldStartPointX,
                                    int worldStartPointY, int displayBlockWidth) const
{
    const auto& currentDimension = world.getCurrentGameScene();
    const auto& player = world.getPlayer();
    const auto& tileSheet = currentDimension.getTileSheet();
    for (int currentDrawX = viewPortStartPointX, x = worldStartPointX;
         currentDrawX <= width;
         currentDrawX += displayBlockWidth, ++x)
    {
        for(int currentDrawY = viewPortStartPointY, y = worldStartPointY;
            currentDrawY <= height;
            currentDrawY += displayBlockWidth, ++y)
        {
            const auto& tileObjects = tileSheet.getTilesAt(x, y);
            for(const auto& tileRef : tileObjects)
            {
                if(tileRef().displayPriority >= Tile::DisplayPriority::SKY)
                {
                    const QRect drawArea(currentDrawX, currentDrawY, displayBlockWidth, displayBlockWidth);
                    const auto& textures = tileRef.tile->textures;
                    const auto texturesSize = textures.size();
                    painter.drawPixmap(drawArea, QPixmap(textures[(paintFrameCount / 25) % texturesSize].c_str()));
                }
            }
        }
    }
}

void WorldPainter::paintWorldOverlay(QPainter & painter, const GameClient & client, const GameWorld & world, QWidget &widget, int width,
                                     int height)
{
    if(world.getWorldStatus().get() == WorldStatus::SWITCHING_SCENE ||
       world.getWorldStatus().get() == WorldStatus::SLEEPING)
    {
        double progress = world.getWorldStatus().getProgress();
        if(progress <= 0.50)
            painter.fillRect(QRect(0, 0, width, height), QColor(0, 0, 0, 255));
        else
            painter.fillRect(QRect(0, 0, width, height), QColor(0, 0, 0, int(255 - 255 * (progress - 0.5) * 2)));
    }
}

void WorldPainter::paintWorldPlayer(QPainter & painter, const GameClient & client, const GameWorld & world, QWidget &widget, int width,
                                    int height, int displayBlockWidth) const
{
    const auto& player = world.getPlayer();
    const QRect playerRect(width / 2 - displayBlockWidth / 2, height / 2 - displayBlockWidth * 6 / 5, displayBlockWidth, displayBlockWidth * 3 / 2);
    const Action* playerAction = player.getCurrentAction();
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
        painter.drawPixmap(playerRect, QPixmap(resID.c_str()));
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
        painter.drawPixmap(playerRect, QPixmap(resID.c_str()));
    }
}

void
WorldPainter::paintActionBeforePlayer(QPainter & painter, const GameClient & client, const GameWorld & world, QWidget &widget, int width,
                                      int height, int displayBlockWidth)
{
    const auto& player = world.getPlayer();
    const auto* playerAction = player.getCurrentAction();
    if(!playerAction)
        return;
    if(typeid(*playerAction) == typeid(const PickupAction&))
        paintPickupActionBF(painter, client, world, widget, width, height, displayBlockWidth);
    if(typeid(*playerAction) == typeid(const SmashAction&))
        paintSmashActionBF(painter, client, world, widget, width, height, displayBlockWidth);
}

void WorldPainter::paintActionAfterPlayer(QPainter & painter, const GameClient & client, const GameWorld & world, QWidget &widget, int width,
                                          int height, int displayBlockWidth)
{
    const auto& player = world.getPlayer();
    const auto* playerAction = player.getCurrentAction();
    if(!playerAction)
        return;
    if(typeid(*playerAction) == typeid(const PickupAction&))
        paintPickupActionAF(painter, client, world, widget, width, height, displayBlockWidth);
    if(typeid(*playerAction) == typeid(const SmashAction&))
        paintSmashActionAF(painter, client, world, widget, width, height, displayBlockWidth);
}

void WorldPainter::paintPickupActionBF(QPainter & painter, const GameClient & client, const GameWorld & world, QWidget &widget, int width,
                                       int height, int displayBlockWidth)
{
    const auto& player = world.getPlayer();
    const auto* playerAction = player.getCurrentAction();
    if(player.getFacing() == Player::Facing::UP)
    {
        const QRect playerRect(int((double)width / 2 - displayBlockWidth * 0.6 / 2),
        int((double)height / 2 - displayBlockWidth * 0.6 / 2 - displayBlockWidth * 0.5),
                int(displayBlockWidth * 0.6),
                int(displayBlockWidth * 0.6));
        painter.drawPixmap(playerRect, QPixmap(dynamic_cast<const PickupAction*>(playerAction)->getItem().getTexture().c_str()));
    }
}

void WorldPainter::paintSmashActionBF(QPainter & painter, const GameClient &, const GameWorld & world, QWidget &widget, int width,
                                      int height, int displayBlockWidth)
{
    const auto& player = world.getPlayer();
    const auto* playerAction = dynamic_cast<const SmashAction*>(player.getCurrentAction());
    if(player.getFacing() == Player::Facing::UP)
    {
        std::string t1;
        if(&playerAction->getToolItem() == ItemInstance("axe").getItem())
            t1 = ":/svl/textures/tools/5_3_10.png";
        const QRect playerRect(int(width / 2.0 - displayBlockWidth / 2.0),
        int((double)height / 2 - displayBlockWidth * 0.6 / 2 - displayBlockWidth * 1.6),
                int(displayBlockWidth),
                int(displayBlockWidth));
        painter.drawPixmap(playerRect, QPixmap(t1.c_str()));
    }
}

void WorldPainter::paintPickupActionAF(QPainter & painter, const GameClient &, const GameWorld & world, QWidget &widget, int width,
                                       int height, int displayBlockWidth)
{
    const auto& player = world.getPlayer();
    const auto* playerAction = player.getCurrentAction();
    if(player.getFacing() == Player::Facing::DOWN)
    {
        const QRect playerRect(int((double)width / 2 - displayBlockWidth * 0.6 / 2),
        int((double)height / 2 - displayBlockWidth * 0.6 / 2 - displayBlockWidth * 0.2),
                int(displayBlockWidth * 0.6),
                int(displayBlockWidth * 0.6));
        painter.drawPixmap(playerRect, QPixmap(dynamic_cast<const PickupAction*>(playerAction)->getItem().getTexture().c_str()));
    }
    else if(player.getFacing() == Player::Facing::LEFT)
    {
        const QRect playerRect(int((double)width / 2 - displayBlockWidth * 0.6 / 2 - displayBlockWidth * 0.23),
        int((double)height / 2 - displayBlockWidth * 0.6 / 2 - displayBlockWidth * 0.2),
                int(displayBlockWidth * 0.6),
                int(displayBlockWidth * 0.6));
        painter.drawPixmap(playerRect, QPixmap(dynamic_cast<const PickupAction*>(playerAction)->getItem().getTexture().c_str()));
    }
    else if(player.getFacing() == Player::Facing::RIGHT)
    {
        const QRect playerRect(int((double)width / 2 - displayBlockWidth * 0.6 / 2 + displayBlockWidth * 0.23),
        int((double)height / 2 - displayBlockWidth * 0.6 / 2 - displayBlockWidth * 0.2),
                int(displayBlockWidth * 0.6),
                int(displayBlockWidth * 0.6));
        painter.drawPixmap(playerRect, QPixmap(dynamic_cast<const PickupAction*>(playerAction)->getItem().getTexture().c_str()));
    }
}

void WorldPainter::paintSmashActionAF(QPainter & painter, const GameClient &, const GameWorld & world, QWidget &widget, int width,
                                      int height, int displayBlockWidth)
{
    const auto& player = world.getPlayer();
    const auto* playerAction = dynamic_cast<const SmashAction*>(player.getCurrentAction());
    if(player.getFacing() == Player::Facing::DOWN)
    {
        std::string t1;
        if(&playerAction->getToolItem() == ItemInstance("axe").getItem())
            t1 = ":/svl/textures/tools/5_1_10.png";
        const QRect playerRect(int(width / 2.0 - displayBlockWidth / 2.0),
        int(height / 2.0 - displayBlockWidth / 2.0 + displayBlockWidth * 0.3),
                int(displayBlockWidth),
                int(displayBlockWidth));
        painter.drawPixmap(playerRect, QPixmap(t1.c_str()));
    }
    else if(player.getFacing() == Player::Facing::LEFT)
    {
        std::string t1, t2;
        if(&playerAction->getToolItem() == ItemInstance("axe").getItem())
            t1 = ":/svl/textures/tools/5_2_10.png", t2 = ":/svl/textures/tools/5_2_9.png";
        {
            const QRect playerRect(int(width / 2.0 - displayBlockWidth / 2.0 - displayBlockWidth * 0.4),
            int(height / 2.0 - displayBlockWidth / 2.0 - displayBlockWidth * 0.2),
                    int(displayBlockWidth),
                    int(displayBlockWidth));
            QPixmap pixmap(t1.c_str());
            pixmap = pixmap.transformed(QTransform(QMatrix().rotate(-90).scale(-1, 1)));
            painter.drawPixmap(playerRect, pixmap);
        }
        {
            const QRect playerRect(int(width / 2.0 - displayBlockWidth / 2.0 - displayBlockWidth * 1.4),
                                   int(height / 2.0 - displayBlockWidth / 2.0 - displayBlockWidth * 0.2),
                                   int(displayBlockWidth),
                                   int(displayBlockWidth));
            QPixmap pixmap(t2.c_str());
            pixmap = pixmap.transformed(QTransform(QMatrix().rotate(-90).scale(-1, 1)));
            painter.drawPixmap(playerRect, pixmap);
        }
    }
    else if(player.getFacing() == Player::Facing::RIGHT)
    {
        std::string t1, t2;
        if(&playerAction->getToolItem() == ItemInstance("axe").getItem())
            t1 = ":/svl/textures/tools/5_2_10.png", t2 = ":/svl/textures/tools/5_2_9.png";
        {
            const QRect playerRect(int(width / 2.0 - displayBlockWidth / 2.0 + displayBlockWidth * 0.4),
                                   int(height / 2.0 - displayBlockWidth / 2.0 - displayBlockWidth * 0.2),
                                   int(displayBlockWidth),
                                   int(displayBlockWidth));
            QPixmap pixmap(t1.c_str());
            pixmap = pixmap.transformed(QTransform(QMatrix().rotate(90)));
            painter.drawPixmap(playerRect, pixmap);
        }
        {
            const QRect playerRect(int(width / 2.0 - displayBlockWidth / 2.0 + displayBlockWidth * 1.4),
                                   int(height / 2.0 - displayBlockWidth / 2.0 - displayBlockWidth * 0.2),
                                   int(displayBlockWidth),
                                   int(displayBlockWidth));
            QPixmap pixmap(t2.c_str());
            pixmap = pixmap.transformed(QTransform(QMatrix().rotate(90)));
            painter.drawPixmap(playerRect, pixmap);
        }
    }
}
