#include "ListChanger.h"
#include "ui_deltask.h"
#include "DatabaseConnector.h"
#include "QMessageBox"
#include "QDateTime"

ListChanger::ListChanger(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ListChanger)
{
    ui->setupUi(this);
    setFixedSize(820,324);
}

ListChanger::~ListChanger()
{
    delete ui;
}

void ListChanger::on_goToMenuButton_clicked()
{
    this->close();
    emit goToMainWindow();
}

void ListChanger::on_showCompletedTask_clicked()
{
    CleanerCompletedTasks *compTask = new CleanerCompletedTasks();
     compTask->show();
}

void ListChanger::on_completedTheTask_clicked()
{
    DatabaseConnector connector;
    QString task;

    task = ui->delT->text();
    ui->comboBox->clearFocus();
    int lengthDoneWord = task.length();
    bool isSomeSymbol = false;

    for(int i = 0; i<task.length(); i++)
    {
        if(task[i]!="" && task[i]!=" ")
        {
            isSomeSymbol=true;
            break;
        }
    }

    if(isSomeSymbol==true && (task[0].isLetter() || (int)task[0].isDigit())){
        if(!connector.openDatabase())
        {
            qDebug()<<"Faild";
            return;
        }

        connector.openDatabase();
        QSqlQuery databaseQuery;
        databaseQuery.prepare("Delete from taskT where password ='"+task+"'");

        if(databaseQuery.exec())
        {
            QMessageBox::about(this,tr(" "),tr("Завдання виконано!!!"));
            connector.closeDatabase();
        }
        else
        {
            QMessageBox::critical(this,tr("error::"),databaseQuery.lastError().text());
        }

    //----------------------------------------------------------------------------

        if(!connector.openDatabase())
        {
            qDebug()<<"Faild";
            return;
        }

        QDateTime time = QDateTime::currentDateTime();
        QString currentTime = time.toString("hh:mm  dd.MM");

        connector.openDatabase();
        QSqlQuery qryWithDone;
        qryWithDone.prepare("insert into doneTaskTable (doneTask) values ('"+task+" - ("+currentTime+")"+"')");

        if(qryWithDone.exec())
        {
            connector.closeDatabase();
        }
        else
        {
            QMessageBox::critical(this,tr("error::"),qryWithDone.lastError().text());
        }

        ui->delT->clear();
    }
    else if(isSomeSymbol==true && task[0]==" ")
    {
        QMessageBox::about(this,tr(" "),tr("Введіть коректні дані!!!"));
    }
    else
    {
        QMessageBox::about(this,tr(" "),tr("Поле не заповнено!!!"));
    }
}

void ListChanger::on_showUncompletedTask_clicked()
{
    DatabaseConnector conn;
    QSqlQueryModel *modal = new QSqlQueryModel();

    conn.openDatabase();

    QSqlQuery *databaseQuery = new QSqlQuery(conn.taskDatabase);
    databaseQuery->prepare("select password from taskT order by idTask desc");

    databaseQuery->exec();
    modal->setQuery(*databaseQuery);

    ui->comboBox->setModel(modal);

    conn.closeDatabase();
    qDebug()<<(modal->rowCount());
}
