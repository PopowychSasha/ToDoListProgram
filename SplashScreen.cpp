#include "SplashScreen.h"
#include "ui_mysplash.h"
#include <QSplashScreen>
#include <QTimer>

SplashScreen::SplashScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SplashScreen)
{
    ui->setupUi(this);
}

SplashScreen::~SplashScreen()
{
    delete ui;
}

void SplashScreen::showSplashScreen()
{
    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/rec/Picture/s.png"));
    splash->show();
    QTimer::singleShot(2500,splash,SLOT(close()));
}
