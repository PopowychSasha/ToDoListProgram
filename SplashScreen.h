#ifndef MYSPLASH_H
#define MYSPLASH_H

#include <QDialog>

namespace Ui {
class SplashScreen;
}

class SplashScreen : public QDialog
{
    Q_OBJECT

public:
    explicit SplashScreen(QWidget *parent = nullptr);
    ~SplashScreen();

private:
    Ui::SplashScreen *ui;
public:
    void showSplashScreen();
};

#endif
