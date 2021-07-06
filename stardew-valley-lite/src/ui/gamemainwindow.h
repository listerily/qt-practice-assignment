#ifndef GAMEMAINWINDOW_H
#define GAMEMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class GameMainWindow;
}

class GameMainWindow : public QMainWindow
{
    Q_OBJECT
private:

public:
    explicit GameMainWindow(QWidget *parent = nullptr);
    ~GameMainWindow() override;

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::GameMainWindow *ui;
};

#endif // GAMEMAINWINDOW_H
