#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class DatabaseConnector; }
QT_END_NAMESPACE

class DatabaseConnector : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase taskDatabase;
    void closeDatabase();
    bool openDatabase();

public:
    DatabaseConnector(QWidget *parent = nullptr);
    ~DatabaseConnector();

private:
    Ui::DatabaseConnector *ui;

};
#endif
