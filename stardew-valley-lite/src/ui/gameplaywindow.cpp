#include "gameplaywindow.h"
#include "ui_gameplaywindow.h"

#include "painter/GamePainter.h"

GamePlayWindow::GamePlayWindow(const GameWorld& world, QWidget *parent) :
    QWidget(parent),
    currentWorld(world),
    ui(new Ui::GamePlayWindow)
{
    ui->setupUi(this);
    setWindowTitle("Stardew Valley Lite");
    paintTickProcessed = false;
}

GamePlayWindow::~GamePlayWindow()
{
    delete ui;
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
    GamePainter(currentWorld).paint(*this, width(), height());
    QWidget::paintEvent(event);
}
