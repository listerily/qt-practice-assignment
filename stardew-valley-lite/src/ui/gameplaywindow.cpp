#include "gameplaywindow.h"
#include "ui_gameplaywindow.h"

#include <QKeyEvent>

#include "painter/WorldPainter.h"
#include "../game/world/GameWorld.h"
#include "../game/inventory/Inventory.h"
#include "../game/item/Item.h"
#include "../game/GameClient.h"
#include "../game/InputHandler.h"

#include <QLabel>
#include <sstream>

GamePlayWindow::GamePlayWindow(GameClient& client, QWidget *parent) :
    gameClient(client),
    QWidget(parent),
    currentWorld(*client.getCurrentWorld()),
    inputHandler(client.getInputHandler()),
    ui(new Ui::GamePlayWindow)
{
    ui->setupUi(this);
    setWindowTitle("Stardew Valley Lite");

    painter = new WorldPainter;
    currentSlotID = 0;

    buttons = {ui->button_0, ui->button_1, ui->button_2, ui->button_3, ui->button_4, ui->button_5, ui->button_6, ui->button_7};
    for(int i = 0; i < 8; ++i)
    {
        connect(buttons[i], &QPushButton::clicked, this, [=](){this->slotButtonClicked(i);});
        buttons[i]->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        labels[i] = new QLabel("", buttons[i]);
        labels[i]->setGeometry(18, 8, labels[i]->width(), labels[i]->height());
        labels[i]->setStyleSheet("QLabel{color:black;font-weight:bold;}");
        labels[i]->show();
    }


    selectSlot(0);
}

GamePlayWindow::~GamePlayWindow()
{
    delete ui;
    delete painter;
}

void GamePlayWindow::notifyPaintTick()
{
    checkInventoryUpdates();
    update();
}

void GamePlayWindow::paintEvent(QPaintEvent *event)
{
    painter->paint(gameClient, *gameClient.getCurrentWorld(), *this, width(), height());
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
    buttons[currentSlotID]->setStyleSheet("QPushButton{border-image: url(:svl/textures/ui/not_selected_slot.png);}");
    currentSlotID = id;
    currentWorld.getPlayerController().selectInventorySlot(id);
    buttons[id]->setStyleSheet("QPushButton{border-image: url(:svl/textures/ui/selected_slot.png);}");
}

void GamePlayWindow::notifyInventoryUpdated(unsigned int slot)
{
    const auto& pItemInstance = inventoryUpdates[slot];
    if(pItemInstance.empty())
    {
        buttons[slot]->setIcon(QIcon());
        labels[slot]->setText("");
        labels[slot]->setGeometry(20, 10, labels[slot]->width(), labels[slot]->height());
    }
    else
    {
        std::stringstream stream;
        stream << pItemInstance.count;
        QPixmap pixmap(pItemInstance.item->getTexture().c_str());
        pixmap = pixmap.scaled(64, 64);
        QIcon ButtonIcon(pixmap);
        buttons[slot]->setIcon(ButtonIcon);
        buttons[slot]->setIconSize(QSize(40, 40));
        labels[slot]->setText(stream.str().c_str());
        labels[slot]->setGeometry(18, 8, labels[slot]->width(), labels[slot]->height());
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
            inventoryUpdates[i] = inv.getItemInstances()[i];
            notifyInventoryUpdated(i);
        }
        return;
    }

    for(int i = 0; i < inv.size(); ++i)
    {
        if(inv.getItemInstances()[i] != inventoryUpdates[i])
        {
            inventoryUpdates[i] = inv.getItemInstances()[i];
            notifyInventoryUpdated(i);
        }
    }
}

void GamePlayWindow::wheelEvent(QWheelEvent *event)
{
    QWidget::wheelEvent(event);
    painter->zoom(-event->angleDelta().y() / 60);
}

void GamePlayWindow::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    auto& playerController = currentWorld.getPlayerController();
    if(event->button() == Qt::LeftButton)
    {
        double x = event->x();
        double y = event->y();
        double width = this->width();
        double height = this->height() + 15.0;
        double k = (double)height / width;
        if(y < k * x && y < height - k * x)
            playerController.turn(Player::Facing::UP);
        else if(y < k * x && y > height - k * x)
            playerController.turn(Player::Facing::RIGHT);
        else if(y > k * x && y > height - k * x)
            playerController.turn(Player::Facing::DOWN);
        else if(y > k * x && y < height - k * x)
            playerController.turn(Player::Facing::LEFT);

        currentWorld.getPlayerController().interact(false);
    }
    else if(event->button() == Qt::RightButton)
    {
        currentWorld.getPlayerController().interact(true);
    }
}

