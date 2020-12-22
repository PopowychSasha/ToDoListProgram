
#include "CleanerComletedTasks.h"
#include "ui_completedtasks.h"
#include "DatabaseConnector.h"
#include <QMessageBox>

CleanerCompletedTasks::CleanerCompletedTasks(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CleanerCompletedTasks)
{
    ui->setupUi(this);

    DatabaseConnector connector;
    QSqlQueryModel *modal = new QSqlQueryModel();
    setFixedSize(658,434);
    connector.openDatabase();

    QSqlQuery *qryWithDone = new QSqlQuery(connector.taskDatabase);
    qryWithDone->prepare("select doneTask from doneTaskTable order by idT desc");

    qryWithDone->exec();
    modal->setQuery(*qryWithDone);

    ui->listViewForDoneTask->setModel(modal);

    connector.closeDatabase();
}

CleanerCompletedTasks::~CleanerCompletedTasks()
{
    delete ui;
}

void CleanerCompletedTasks::on_clearList_clicked()
{
    QMessageBox::StandardButton reply;
    reply=QMessageBox::question(this," ","Список буде очищено назавжди.\n Ви впевненні що хочете зробити це?",QMessageBox::Yes|QMessageBox::No);

    if(reply==QMessageBox::Yes)
    {
        DatabaseConnector conn;

        if(!conn.openDatabase())
        {
             qDebug()<<"Faild";
             return;
        }

        conn.openDatabase();
        QSqlQuery qryWithDone;
        qryWithDone.prepare("Delete from doneTaskTable");

        if(qryWithDone.exec())
        {
            QMessageBox::information(this,tr(" "),tr("Список видалений успішно"));
            conn.closeDatabase();
        }
        else
        {
            QMessageBox::critical(this,tr("error::"),qryWithDone.lastError().text());
        }
        this->close();
    }
    else
    {
        this->close();
    }
}
