#include <QApplication>
#include <QPushButton>

#include "src/ui/gamemainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameMainWindow mainWindow;
    mainWindow.show();
    return QApplication::exec();
}
