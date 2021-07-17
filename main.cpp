#include "mainwindow.h"

#include <QApplication>
#include<QSqlDatabase>
#include"questions.h"
#include<QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("12345");
    db.setDatabaseName("ieeehackathon");
    db.open();

    //MainWindow w;
    questions w;
    w.show();
    return a.exec();
}
