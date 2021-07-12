#include "gameplaywindow.h"
#include "ui_gameplaywindow.h"

#include <QKeyEvent>

#include "painter/GamePainter.h"
#include "../game/world/GameWorld.h"

GamePlayWindow::GamePlayWindow(GameWorld& world, QWidget *parent) :
    QWidget(parent),
    currentWorld(world),
    ui(new Ui::GamePlayWindow)
{
    ui->setupUi(this);
    setWindowTitle("Stardew Valley Lite");
    paintTickProcessed = false;
    painter = new GamePainter(world);
}

GamePlayWindow::~GamePlayWindow()
{
    delete ui;
    delete painter;
}

void GamePlayWindow::notifyPaintTick()
{
    paintTickProcessed = false;
    update();
}

bool GamePlayWindow::isPaintTickProcessed() const
{
    return paintTickProcessed;
}
void GamePlayWindow::paintEvent(QPaintEvent *event)
{
    paintTickProcessed = true;
    painter->paint(*this, width(), height());
    QWidget::paintEvent(event);
}

void GamePlayWindow::keyPressEvent(QKeyEvent *event)
{
    QWidget::keyPressEvent(event);

    if(event->key() == Qt::Key_W || event->key() == Qt::Key_Up)
        currentWorld.getPlayerController().keyUp();
    if(event->key() == Qt::Key_A || event->key() == Qt::Key_Left)
        currentWorld.getPlayerController().keyLeft();
    if(event->key() == Qt::Key_S || event->key() == Qt::Key_Down)
        currentWorld.getPlayerController().keyDown();
    if(event->key() == Qt::Key_D || event->key() == Qt::Key_Right)
        currentWorld.getPlayerController().keyRight();
}
