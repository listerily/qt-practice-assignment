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
    currentSlotID = 0;

    pushButtons = {ui->pushButton_0, ui->pushButton_1, ui->pushButton_2, ui->pushButton_3, ui->pushButton_4, ui->pushButton_5, ui->pushButton_6, ui->pushButton_7};
    for(int i = 0; i < 8; ++i)
        connect(pushButtons[i], &QPushButton::clicked, this, [=](){this->slotButtonClicked(i);});
    selectSlot(0);

    QPixmap pixmap(":/svl/textures/items/4_0_3.png");
    pixmap = pixmap.scaled(64, 64);
    QIcon ButtonIcon(pixmap);
    pushButtons[0]->setIcon(ButtonIcon);
    pushButtons[0]->setIconSize(QSize(50, 50));
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
        currentWorld.getPlayerController().moveUp();
    if(event->key() == Qt::Key_A || event->key() == Qt::Key_Left)
        currentWorld.getPlayerController().moveLeft();
    if(event->key() == Qt::Key_S || event->key() == Qt::Key_Down)
        currentWorld.getPlayerController().moveDown();
    if(event->key() == Qt::Key_D || event->key() == Qt::Key_Right)
        currentWorld.getPlayerController().moveRight();
}

void GamePlayWindow::slotButtonClicked(int id)
{
    selectSlot(id);
}

void GamePlayWindow::selectSlot(int id)
{
    pushButtons[currentSlotID]->setStyleSheet("QPushButton{border-image: url(:svl/textures/ui/not_selected_slot.png);}");
    currentSlotID = id;
    currentWorld.getPlayerController().selectInventorySlot(0);
    pushButtons[id]->setStyleSheet("QPushButton{border-image: url(:svl/textures/ui/selected_slot.png);}");
}
