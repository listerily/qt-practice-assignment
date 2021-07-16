#ifndef GAMESTARTWINDOW_H
#define GAMESTARTWINDOW_H

#include <QWidget>

namespace Ui
{
    class GameStartWindow;
}
class QMediaPlayer;

class QMediaPlaylist;

class GameClient;

class GameStartWindow : public QWidget
{
Q_OBJECT

public:
    explicit GameStartWindow(GameClient &, QWidget *parent = nullptr);

    ~GameStartWindow() override;

    void openGame();

    void paintEvent(QPaintEvent *event) override;

private:
    Ui::GameStartWindow *ui;
    GameClient &client;
    QMediaPlayer *mediaPlayer;
    QMediaPlaylist *mediaPlaylist;
};

#endif // GAMESTARTWINDOW_H
