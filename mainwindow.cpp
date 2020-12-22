#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "TaskWriteWindow.h"
#include "QPixmap"
#include "SplashScreen.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    SplashScreen *d = new SplashScreen();

    setFixedSize(864,493);

    d->showSplashScreen();
    ui->setupUi(this);

    QPixmap pix(":/rec/Picture/quickTask.png");
    int wS = ui->label_quickTask->width();
    int hS = ui->label_quickTask->height();

    ui->label_quickTask->setPixmap(pix.scaled(wS,hS, Qt::KeepAspectRatio));

    QPixmap pix2(":/rec/Picture/LT.png");
    int wS2 = ui->label_WriteTask->width();
    int hS2 = ui->label_WriteTask->height();

    ui->label_WriteTask->setPixmap(pix2.scaled(wS2,hS2, Qt::KeepAspectRatio));

    QPixmap pix3(":/rec/Picture/ST.png");
    int wS3 = ui->compTask->width();
    int hS3 = ui->compTask->height();

    ui->compTask->setPixmap(pix3.scaled(wS3,hS3, Qt::KeepAspectRatio));

    addT = new TaskWriteWindow;
    connect(addT, &TaskWriteWindow::goToMainWindow, this, &MainWindow::show);

    delT = new ListChanger();
    connect(delT, &ListChanger::goToMainWindow, this, &MainWindow::show);

    shortList = new QuickTask();
    connect(shortList, &QuickTask::goToMainWindowST, this, &MainWindow::show);

    ui->goToTaskWriteWindow->setStyleSheet("QPushButton{color: #fff;background: rgb(212,75,56);font-weight:900;font-size:20px;} "
                                  "QPushButton:hover{border:3px solid black;color:red;background-color:white;}");
    ui->goToChangeListWindow->setStyleSheet("QPushButton{color: #fff;background: rgb(212,75,56);font-weight:900;font-size:20px;} "
                                  "QPushButton:hover{border:3px solid black;color:red;background-color:white;}");
    ui->goToQuickTaskWindow->setStyleSheet("QPushButton{color: #fff;background: rgb(212,75,56);font-weight:900;font-size:20px;} "
                                  "QPushButton:hover{border:3px solid black;color:red;background-color:white;}");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_goToQuickTaskWindow_clicked()
{
    this->hide();
    shortList->show();
}

void MainWindow::on_goToTaskWriteWindow_clicked()
{
    this->hide();
    addT->show();
}

void MainWindow::on_goToChangeListWindow_clicked()
{
    this->hide();
    delT->show();
}
