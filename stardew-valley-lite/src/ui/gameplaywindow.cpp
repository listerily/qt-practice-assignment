#include "gameplaywindow.h"
#include "ui_gameplaywindow.h"

#include <QKeyEvent>

#include "painter/GamePainter.h"
#include "../game/world/GameWorld.h"
#include "../game/inventory/Inventory.h"
#include "../game/item/Item.h"

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
}

GamePlayWindow::~GamePlayWindow()
{
    delete ui;
    delete painter;
}

void GamePlayWindow::notifyPaintTick()
{
    paintTickProcessed = false;
    notifyInventoryUpdated();
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
        currentWorld.getPlayerController().walkUp();
    if(event->key() == Qt::Key_A || event->key() == Qt::Key_Left)
        currentWorld.getPlayerController().walkLeft();
    if(event->key() == Qt::Key_S || event->key() == Qt::Key_Down)
        currentWorld.getPlayerController().walkDown();
    if(event->key() == Qt::Key_D || event->key() == Qt::Key_Right)
        currentWorld.getPlayerController().walkRight();
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

void GamePlayWindow::notifyInventoryUpdated()
{
    const auto& inv = currentWorld.getPlayerController().getInventory();
    for(const auto& itemInstance : inv.getItemInstances())
    {
        if(!itemInstance.empty())
        {
            QPixmap pixmap(itemInstance.item->getTexture().c_str());
            pixmap = pixmap.scaled(64, 64);
            QIcon ButtonIcon(pixmap);
            pushButtons[0]->setIcon(ButtonIcon);
            pushButtons[0]->setIconSize(QSize(50, 50));
        }
    }
}
