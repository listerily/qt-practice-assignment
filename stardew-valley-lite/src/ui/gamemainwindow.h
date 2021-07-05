#ifndef GAMEMAINWINDOW_H
#define GAMEMAINWINDOW_H

#include <QDialog>

namespace Ui {
class GameMainWindow;
}

class GameMainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GameMainWindow(QWidget *parent = nullptr);
    ~GameMainWindow();

private:
    Ui::GameMainWindow *ui;
};

#endif // GAMEMAINWINDOW_H
