#ifndef DATABASE_H
#define DATABASE_H
#include <QDebug>
#include <QtSql>
#include <QDebug>
#include <QSqlTableModel>
#include <iostream>


class Database
{
private:
    QSqlDatabase db;
public:
    std::string query_string;
    QSqlQuery query;
    void database_init()
    {
        db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("localhost");      // IP 또는 DNS Host name
        db.setDatabaseName("library"); // DB명
        db.setUserName("root");     // 계정 명
        db.setPassword("1234");     // 계정 Password

        if(!db.open())
        {
            qDebug()<<"실패";
            std::cout<<db.lastError().text().toStdString()<<std::endl;
            exit(1);
        }
        std::cout<<"Database Connected!"<<std::endl;
    }

};

#endif // DATABASE_H
