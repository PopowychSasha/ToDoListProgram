#include "TaskWriteWindow.h"
#include "ui_addtask.h"
#include "ui_TaskWriteWindow.h"
#include <QMessageBox>
#include "DatabaseConnector.h"
#include "QPixmap"
#include "QDateTime"

TaskWriteWindow::TaskWriteWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TaskWriteWindow)
{
    ui->setupUi(this);
    setFixedSize(765,424);
    QPixmap returnPicture(":/rec/Picture/ret.png");
    int widthLabelRet = ui->labelRet->width();
    int heightLabelRet = ui->labelRet->height();
    ui->showTaskButton->setText("Показати список");
    ui->labelRet->setPixmap(returnPicture.scaled(widthLabelRet,heightLabelRet, Qt::KeepAspectRatio));

    QPixmap listPicture(":/rec/Picture/list.png");
    int widthListPicture = ui->labelShow->width();
    int heightListPicture = ui->labelShow->height();

    ui->labelShow->setPixmap(listPicture.scaled(widthListPicture,heightListPicture, Qt::KeepAspectRatio));
}

TaskWriteWindow::~TaskWriteWindow()
{
    delete ui;
}

void TaskWriteWindow::on_goToMenu_clicked()
{
    this->close();
    emit goToMainWindow();
}


void TaskWriteWindow::on_writeTaskInDatabase_clicked()
{
    DatabaseConnector connector;
    QString password;

    password = ui->lineEdit->text();
    ui->lineEdit->clear();

    int lengthDoneWord = password.length();
    bool isSomeSymbol = false;

    for(int i = 0; i<password.length(); i++)
    {
        if(password[i]!="" && password[i]!=" ")
        {
            isSomeSymbol=true;
            break;
        }
    }

    if(password[0]==" " && isSomeSymbol==true)
    {
        QMessageBox::about(this,tr(" "),tr("Введіть коректні дані!!!"));
    }
    else if(isSomeSymbol==true && password[0]!=" ")
    {
        if(!connector.openDatabase())
        {
             qDebug()<<"Faild";
             return;
        }

        connector.openDatabase();
        QSqlQuery qry;

        QDateTime time = QDateTime::currentDateTime();
        QString currentTime = time.toString("hh:mm  dd.MM");

        qry.prepare("insert into taskT (password) values ('"+password+" ("+currentTime+")""')");

        if(qry.exec())
        {
            QMessageBox::about(this,tr(" "),tr("Завдання добавлено в список"));
            connector.closeDatabase();
        }
        else
        {
            QMessageBox::information(this,tr("error::"),qry.lastError().text());
        }
    }
    else if(isSomeSymbol==false)
    {
        QMessageBox::about(this,tr(" "),tr("Поле не заповнено!!!"));
    }
}

void TaskWriteWindow::on_showTaskButton_clicked()
{
    DatabaseConnector connector;
    QSqlQueryModel *modal = new QSqlQueryModel();

    connector.openDatabase();

    QSqlQuery *query = new QSqlQuery(connector.taskDatabase);
    query->prepare("select password from taskT");

    query->exec();
    modal->setQuery(*query);

    ui->listView->setModel(modal);

    connector.closeDatabase();
    qDebug()<<(modal->rowCount());
}
