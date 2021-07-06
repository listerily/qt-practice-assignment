#ifndef GAMEPLAYWINDOW_H
#define GAMEPLAYWINDOW_H

#include <QWidget>

namespace Ui {
class GamePlayWindow;
}
class GameWorld;
class GamePlayWindow : public QWidget
{
    Q_OBJECT
private:
    const GameWorld& currentWorld;
    bool paintTickProcessed;
public:
    explicit GamePlayWindow(GameWorld const& world, QWidget *parent = nullptr);
    ~GamePlayWindow() override;

    void paintEvent(QPaintEvent *event) override;
    void notifyPaintTick();
    bool isPaintTickProcessed() const;
private:
    Ui::GamePlayWindow *ui;
};

#endif // GAMEPLAYWINDOW_H
