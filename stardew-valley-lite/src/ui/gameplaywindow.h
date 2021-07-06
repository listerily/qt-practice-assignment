#ifndef GAMEPLAYWINDOW_H
#define GAMEPLAYWINDOW_H

#include <QWidget>

namespace Ui {
class GamePlayWindow;
}

class GamePlayWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GamePlayWindow(QWidget *parent = nullptr);
    ~GamePlayWindow();

private:
    Ui::GamePlayWindow *ui;
};

#endif // GAMEPLAYWINDOW_H
