#include "gamestartwindow.h"
#include "ui_gamestartwindow.h"
#include "gameplaywindow.h"
#include "../game/GameClient.h"
#include <QPainter>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>

GameStartWindow::GameStartWindow(GameClient &client, QWidget *parent)
        : client(client),
          QWidget(parent),
          ui(new Ui::GameStartWindow)
{
    ui->setupUi(this);
    setWindowTitle("Stardew Valley Lite");
    mediaPlaylist = new QMediaPlaylist;
    mediaPlaylist->addMedia(QMediaContent(QUrl("qrc:/svl/audio/audio/0000014f.wav")));
    mediaPlaylist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    mediaPlayer = new QMediaPlayer(this);
    mediaPlayer->setPlaylist(mediaPlaylist);
    mediaPlayer->play();
    connect(ui->button_0, &QPushButton::clicked, this, &GameStartWindow::openGame);
}

GameStartWindow::~GameStartWindow()
{
    delete ui;
    delete mediaPlayer;
    delete mediaPlaylist;
}

extern GamePlayWindow *globalGamePlayWindow;

void GameStartWindow::openGame()
{
    mediaPlayer->stop();
    client.createWorld();
    globalGamePlayWindow = new GamePlayWindow(client);
    globalGamePlayWindow->show();
    close();
}

void GameStartWindow::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter(this).drawImage(QRect(0, 0, width(), height()), QImage(":/svl/textures/ui/stardewPanorama.png"));
}
