#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "TaskWriteWindow.h"
#include "ListChanger.h"
#include "QuickTaskWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_goToQuickTaskWindow_clicked();
    void on_goToTaskWriteWindow_clicked();
    void on_goToChangeListWindow_clicked();

private:
    Ui::MainWindow *ui;
    TaskWriteWindow * addT;
    ListChanger * delT;
    QuickTask *shortList;

};
#endif
