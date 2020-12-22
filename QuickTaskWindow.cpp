#include "QuickTaskWindow.h"
#include <QLabel>
#include <QToolBar>
#include <QBoxLayout>

QuickTask::QuickTask()
{
    QWidget* widgetForQuickTask = new QWidget();

    setWindowTitle("To Do List");

    setWindowIcon(QIcon(":/rec/Picture/list.png"));

    setFixedSize(1300,700);

    widgetForQuickTask->setStyleSheet("background-color: #ffffff");
    setCentralWidget(widgetForQuickTask);

    QVBoxLayout* pMainLayout = new QVBoxLayout();
    widgetForQuickTask->setLayout(pMainLayout);

    QHBoxLayout* pHLayoutLabels = new QHBoxLayout();
    pMainLayout->addLayout(pHLayoutLabels);

    QLabel* plblPending = new QLabel("             Заплановані", this);
    plblPending->setStyleSheet("font-size:45px;font-weight:900;");
    pHLayoutLabels->addWidget(plblPending);

    QLabel* plblCompleted = new QLabel("                Виконані", this);
    plblCompleted->setStyleSheet("font-size: 45px;font-weight:900;");
    pHLayoutLabels->addWidget(plblCompleted);

    QHBoxLayout* pHLayout = new QHBoxLayout();
    pMainLayout->addLayout(pHLayout);

    PendingTask = new QListView(this);

    PendingTask->setDragEnabled(true);
    PendingTask->setAcceptDrops(true);
    PendingTask->setDropIndicatorShown(true);
    PendingTask->setDefaultDropAction(Qt::MoveAction);
    pHLayout->addWidget(PendingTask);

    CompletedTask = new QListView(this);
    CompletedTask->setDragEnabled(true);
    CompletedTask->setAcceptDrops(true);
    CompletedTask->setDropIndicatorShown(true);
    CompletedTask->setDefaultDropAction(Qt::MoveAction);
    pHLayout->addWidget(CompletedTask);

    PendingTask->setModel(new QStringListModel());
    CompletedTask->setModel(new QStringListModel());

    PendingTask->setStyleSheet
    ("QListView { font-size: 20pt; color:white; font-weight: bold; }"
     "QListView::item { background-color: #E74C3C; padding: 1%;"
     "border: 1px solid #C0392B; }"
     "QListView::item::hover{background-color: #ffffff;}"
     "QListView::item::hover{color: #C0392B}");

    CompletedTask->setStyleSheet
    ("QListView { font-size: 20pt;color:white;  font-weight: bold; }"
     "QListView::item { background-color: #2ECC71; padding: 1%;"
     "border: 1px solid #27AE60;}"
     "QListView::item::hover{background-color:#ffffff;}"
      "QListView::item::hover{color: #27AE60}");

    QToolBar* pToolBar = new QToolBar(this);
    addToolBar(pToolBar);

    ReturnAction = new QAction();
    ReturnAction->setIcon(QIcon(":/rec/Picture/return.png"));
    connect(ReturnAction, &QAction::triggered, this, &QuickTask::onButtonToMainWindow);

    AddAction = new QAction();
    AddAction->setIcon(QIcon(":/rec/Picture/add.png"));
    connect(AddAction, &QAction::triggered, this, &QuickTask::onAdd);

    RemoveAction = new QAction();
    RemoveAction->setIcon(QIcon(":/rec/Picture/remove.png"));
    connect(RemoveAction, &QAction::triggered, this, &QuickTask::onRemove);

    pToolBar->addAction(ReturnAction);
    pToolBar->addAction(AddAction);
    pToolBar->addAction(RemoveAction);
}

void QuickTask::onAdd()
{
    PendingTask->model()->insertRow(PendingTask->model()->rowCount());
    QModelIndex oIndex = PendingTask->model()->index(
                PendingTask->model()->rowCount() -1, 0);

    PendingTask->edit(oIndex);
}

void QuickTask::onRemove()
{
    QModelIndex oIndex = PendingTask->currentIndex();
    PendingTask->model()->removeRow(oIndex.row());
}

void QuickTask::onButtonToMainWindow()
{
    this->close();
    emit goToMainWindowST();
}
