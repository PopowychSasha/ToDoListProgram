#include "DatabaseConnector.h"
#include "ui_login.h"

DatabaseConnector::DatabaseConnector(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DatabaseConnector)
{
}

DatabaseConnector::~DatabaseConnector()
{
    delete ui;
}

void DatabaseConnector::closeDatabase()
{
    taskDatabase.close();
    taskDatabase.removeDatabase(QSqlDatabase::defaultConnection);
}

bool DatabaseConnector::openDatabase()
{

    taskDatabase = QSqlDatabase::addDatabase("QSQLITE");
    taskDatabase.setDatabaseName("C:/DbForToDoList/TaskDB.db");

    if(!taskDatabase.open())
    {
        qDebug()<<"Error!!!";
        return false;
    }
    else
    {
        qDebug()<<"Coneccted";
        return true;
    }
}
