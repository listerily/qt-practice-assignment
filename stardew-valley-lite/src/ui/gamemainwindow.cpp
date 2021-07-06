#include <QPen>
#include <QPainter>
#include "gamemainwindow.h"
#include "ui_gamemainwindow.h"

GameMainWindow::GameMainWindow(QWidget *parent) :
        QMainWindow(parent),
    ui(new Ui::GameMainWindow)
{
    ui->setupUi(this);
}

GameMainWindow::~GameMainWindow()
{
    delete ui;
}

void GameMainWindow::paintEvent(QPaintEvent *event)
{
    QPen qPen;
    qPen.setColor(Qt::green);
    QPainter painter(this);
    painter.setPen(qPen);
    painter.drawRect(200, 200, 700, 700);

    //QWidget::paintEvent(event);
}
