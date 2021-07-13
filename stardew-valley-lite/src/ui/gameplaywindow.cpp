#include "gameplaywindow.h"
#include "ui_gameplaywindow.h"

#include <QKeyEvent>

#include "painter/GamePainter.h"
#include "../game/world/GameWorld.h"
#include "../game/inventory/Inventory.h"
#include "../game/item/Item.h"
#include "../game/GameClient.h"
#include "../game/InputHandler.h"

GamePlayWindow::GamePlayWindow(GameClient& client, QWidget *parent) :
    gameClient(client),
    QWidget(parent),
    currentWorld(*client.getCurrentWorld()),
    inputHandler(client.getInputHandler()),
    ui(new Ui::GamePlayWindow)
{
    ui->setupUi(this);
    setWindowTitle("Stardew Valley Lite");
    paintTickProcessed = false;
    painter = new GamePainter(currentWorld);
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
    checkInventoryUpdates();
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

    inputHandler.keyPressEvent(event->key());
}

void GamePlayWindow::keyReleaseEvent(QKeyEvent *event)
{
    QWidget::keyReleaseEvent(event);

    inputHandler.keyReleaseEvent(event->key());
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

void GamePlayWindow::notifyInventoryUpdated(unsigned int slot)
{
    const auto* item = inventoryUpdates[slot];
    if(item == nullptr)
    {
        pushButtons[slot]->setIcon(QIcon());
    }
    else
    {
        QPixmap pixmap(item->getTexture().c_str());
        pixmap = pixmap.scaled(64, 64);
        QIcon ButtonIcon(pixmap);
        pushButtons[slot]->setIcon(ButtonIcon);
        pushButtons[slot]->setIconSize(QSize(50, 50));
    }
}

void GamePlayWindow::checkInventoryUpdates()
{
    const auto& inv = currentWorld.getPlayerController().getInventory();
    if(inventoryUpdates.size() != inv.size())
    {
        inventoryUpdates.resize(inv.size());
        for(unsigned int i = 0; i < 8; ++i)
        {
            inventoryUpdates[i] = inv.getItemInstances()[i].item;
            notifyInventoryUpdated(i);
        }
        return;
    }

    for(int i = 0; i < inv.size(); ++i)
    {
        if(inv.getItemInstances()[i].item != inventoryUpdates[i])
        {
            inventoryUpdates[i] = inv.getItemInstances()[i].item;
            notifyInventoryUpdated(i);
        }
    }
}

void GamePlayWindow::wheelEvent(QWheelEvent *event)
{
    QWidget::wheelEvent(event);
    painter->zoom(-event->angleDelta().y() / 60);
}

