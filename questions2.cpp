#include "questions2.h"
#include "ui_questions2.h"
#include "questions.h"
#include<QDebug>
#include<QSqlQuery>
#include<QSqlRecord>
#include<QMessageBox>

questions2::questions2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::questions2)
{
    ui->setupUi(this);
    ui->label_2->setText(questions::listOfSym2[0]);
}

questions2::~questions2()
{
    delete ui;
}

void questions2::on_pushButton_clicked()
{
    int f=0;
    while(true){
        newlist.clear();
        int value;

        if(ui->radioButton->isChecked()){
            value = 1;
        }
        else{
            value = 0;
        }

        QList<QString> newlist2;
        QSqlQuery qry;


        for(int x = 0; x < questions::list2.length(); x++){

            qry.prepare("SELECT * FROM mytable WHERE prognosis = :name");
            qry.bindValue(":name", questions::list2[x]);
            if(qry.exec()){
                while(qry.next()){

                    for(int c=0;c<130;c++){

                        QSqlRecord rec = qry.record();
                        QString nameCol = rec.fieldName(c);
                        if(nameCol == questions::listOfSym2[f]){
                            if(qry.value(c).toInt() == value){
                                newlist.append(questions::list2[x]);
                            }
                        }
                    }
                }
            }

        }

        if(newlist.length()==1){
            qDebug()<<"ahah";
            break;
        }
        else{
            f++;
            questions::list2.clear();
            ui->label_2->setText(questions::listOfSym2[f]);
            ui->radioButton->setChecked(false);
            ui->radioButton_2->setChecked(false);

            qDebug()<<newlist;
            qDebug()<<newlist.length();
            for(int i=0; i<newlist.length();i++){
                //QString=newlist[i];
                questions::list2.append(newlist[i]);
                //qDebug()<<questions::list2[i];
            }
        }



    }
    QMessageBox::information(nullptr, "Information", QString("You have %1").arg(newlist[0]));

    /* else{


            ui->label_2->setText(questions::listOfSym2[1]);
            if(ui->radioButton->isChecked()){
                value = 1;
            }
            else{
                value = 0;
            }

            for(int x = 0; x < newlist.length(); x++){
                qry.prepare("SELECT * FROM mytable WHERE prognosis = :name");
                qry.bindValue(":name", newlist[x]);
                if(qry.exec()){
                    while(qry.next()){
                        for(int c=0;c<130;c++){

                            QSqlRecord rec = qry.record();
                            QString nameCol = rec.fieldName(c);
                            if(nameCol == questions::listOfSym2[1]){
                                if(qry.value(c).toInt() == value){
                                    newlist2.append(newlist[x]);
                                }
                            }
                        }
                    }
                }
            }

            if(newlist2.length() == 1){
                QMessageBox::information(nullptr, "Information", QString("You have %1").arg(newlist2[0]));

            }
        }*/

    //qDebug() << newlist2;

}
