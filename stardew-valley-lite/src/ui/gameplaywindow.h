#ifndef GAMEPLAYWINDOW_H
#define GAMEPLAYWINDOW_H

#include <QWidget>

namespace Ui
{
    class GamePlayWindow;
}
class GameWorld;

class WorldPainter;

class QPushButton;

class ItemInstance;

class GameClient;

class InputHandler;

class QLabel;

class QMediaPlayer;

class QMediaPlaylist;

class GamePlayWindow : public QWidget
{
Q_OBJECT
private:
    GameWorld &currentWorld;
    GameClient &gameClient;
    InputHandler &inputHandler;
    WorldPainter *painter;
    int currentSlotID;
    std::vector<ItemInstance> inventoryUpdates;
public:
    explicit GamePlayWindow(GameClient &, QWidget *parent = nullptr);

    ~GamePlayWindow() override;

    void paintEvent(QPaintEvent *event) override;

    void notifyPaintTick();

    void keyPressEvent(QKeyEvent *event) override;

    void keyReleaseEvent(QKeyEvent *event) override;

    void wheelEvent(QWheelEvent *event) override;

    void mousePressEvent(QMouseEvent *event) override;

private:
    void notifyInventoryUpdated(unsigned int slot);

    void checkInventoryUpdates();

    void slotButtonClicked(int);

    void selectSlot(int);

    std::array<QPushButton *, 8> buttons{};
    std::array<QLabel *, 8> labels{};
    Ui::GamePlayWindow *ui;
    QMediaPlayer *mediaPlayer;
    QMediaPlaylist *mediaPlaylist;
};

#endif // GAMEPLAYWINDOW_H
