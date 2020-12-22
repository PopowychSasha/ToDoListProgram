#ifndef TODOLIST_H
#define TODOLIST_H

#include <QMainWindow>
#include <QListView>
#include <QStringListModel>

class QuickTask : public QMainWindow
{
    Q_OBJECT
public:
    QuickTask();

signals:
    void goToMainWindowST();

private:

    QListView* CompletedTask = nullptr;
    QListView* PendingTask = nullptr;

    QAction* AddAction = nullptr;
    QAction* RemoveAction = nullptr;
    QAction* ReturnAction = nullptr;

public slots:
    void onButtonToMainWindow();
    void onAdd();
    void onRemove();
};

#endif
