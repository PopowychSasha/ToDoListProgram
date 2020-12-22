#ifndef COMPLETEDTASKS_H
#define COMPLETEDTASKS_H

#include <QWidget>

namespace Ui {
class CleanerCompletedTasks;
}

class CleanerCompletedTasks : public QWidget
{
    Q_OBJECT

public:
    explicit CleanerCompletedTasks(QWidget *parent = nullptr);
    ~CleanerCompletedTasks();

private slots:

    void on_clearList_clicked();

private:
    Ui::CleanerCompletedTasks *ui;
};

#endif
