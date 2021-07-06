#include "gameplaywindow.h"
#include "ui_gameplaywindow.h"

GamePlayWindow::GamePlayWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GamePlayWindow)
{
    ui->setupUi(this);
}

GamePlayWindow::~GamePlayWindow()
{
    delete ui;
}
