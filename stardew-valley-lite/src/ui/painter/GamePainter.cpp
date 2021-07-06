//
// Created by listerily on 2021/7/6.
//

#include "GamePainter.h"

#include <QPainter>
#include <QPen>
#include <QWidget>

GamePainter::GamePainter(const GameWorld &world): gameWorld(world)
{

}

void GamePainter::paint(QWidget& widget, int width, int height) const
{
    QPainter painter(&widget);
    painter.drawPixmap(QRect(0, 0, 100, 100), QPixmap(":/svl/textures/tiles/0_0_2.png"));
    painter.drawRect(QRect(200, 200, 210, 210));
}
