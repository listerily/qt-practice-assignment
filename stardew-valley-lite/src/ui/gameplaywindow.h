#ifndef GAMEPLAYWINDOW_H
#define GAMEPLAYWINDOW_H

#include <QWidget>

namespace Ui {
class GamePlayWindow;
}
class GameWorld;
class GamePainter;
class QPushButton;
class GamePlayWindow : public QWidget
{
    Q_OBJECT
private:
    GameWorld& currentWorld;
    bool paintTickProcessed;
    GamePainter* painter;
    int currentSlotID;
public:
    explicit GamePlayWindow(GameWorld & world, QWidget *parent = nullptr);
    ~GamePlayWindow() override;

    void paintEvent(QPaintEvent *event) override;
    void notifyPaintTick();
    bool isPaintTickProcessed() const;
    void keyPressEvent(QKeyEvent *event) override;

private:
    void slotButtonClicked(int);
    void selectSlot(int);
    std::array<QPushButton*, 8> pushButtons{};
    Ui::GamePlayWindow *ui;
};

#endif // GAMEPLAYWINDOW_H
