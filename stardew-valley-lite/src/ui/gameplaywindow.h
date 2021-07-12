#ifndef GAMEPLAYWINDOW_H
#define GAMEPLAYWINDOW_H

#include <QWidget>

namespace Ui {
class GamePlayWindow;
}
class GameWorld;
class GamePainter;
class GamePlayWindow : public QWidget
{
    Q_OBJECT
private:
    GameWorld& currentWorld;
    bool paintTickProcessed;
    GamePainter* painter;
public:
    explicit GamePlayWindow(GameWorld & world, QWidget *parent = nullptr);
    ~GamePlayWindow() override;

    void paintEvent(QPaintEvent *event) override;
    void notifyPaintTick();
    bool isPaintTickProcessed() const;
    void keyPressEvent(QKeyEvent *event) override;
private:
    Ui::GamePlayWindow *ui;
};

#endif // GAMEPLAYWINDOW_H
