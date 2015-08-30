#include "mainwindow.h"
#include <QApplication>
#include <QtGui>
#include "GamePanel.h"
#include "GameController.h"
#include "ViewComponent/gamebutton.h"
#include "ViewComponent/gamemessagebox.h"
#include "ViewComponent/gameinfoviewer.h"
#include "ViewComponent/gamesizechangebutton.h"
#include "ViewComponent/gamemenuinterface.h"
#include "ViewComponent/gamechoosebox.h"
#include "ViewComponent/gamelevelchooser.h"
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(QCoreApplication::applicationDirPath()+"/Resources/Image/icon.ico"));

    MainWindow w;
    w.show();

    return a.exec();
}
