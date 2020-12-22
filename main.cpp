#include "MainWindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow userInterface ;
    QTimer::singleShot(2500,&userInterface,SLOT(show()));
    return a.exec();
}
