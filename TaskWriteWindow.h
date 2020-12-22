#ifndef ADDTASK_H
#define ADDTASK_H

#include <QWidget>
namespace Ui {

class TaskWriteWindow;
}

class TaskWriteWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TaskWriteWindow(QWidget *parent = nullptr);
    ~TaskWriteWindow();

signals:
    void goToMainWindow();

private slots:

    void on_showTaskButton_clicked();
    void on_goToMenu_clicked();
    void on_writeTaskInDatabase_clicked();

private:
    Ui::TaskWriteWindow *ui;
};

#endif
