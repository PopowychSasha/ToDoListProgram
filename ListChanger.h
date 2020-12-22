#ifndef DELTASK_H
#define DELTASK_H

#include <QWidget>
#include "CleanerComletedTasks.h"

namespace Ui {
class ListChanger;
}

class ListChanger : public QWidget
{
    Q_OBJECT

public:
    explicit ListChanger(QWidget *parent = nullptr);
    ~ListChanger();

signals:
    void goToMainWindow();

private slots:

    void on_goToMenuButton_clicked();
    void on_showCompletedTask_clicked();
    void on_completedTheTask_clicked();
    void on_showUncompletedTask_clicked();

private:
    Ui::ListChanger *ui;
};

#endif
