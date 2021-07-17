#include "questions.h"
#include "ui_questions.h"
#include<QSqlQuery>
#include<QDebug>
#include <QList>
#include<QSqlRecord>
#include"questions2.h"


QList<QString> questions::listOfSym2;
QList<QString> questions::list2;

questions::questions(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::questions)
{
    ui->setupUi(this);
}

questions::~questions()
{
    delete ui;
}

void questions::on_pushButton_clicked()
{

    int skin_rash = 0;
    int chills = 0;
    int vomiting = 0;
    int fatigue = 0;
    int cough = 0;
    int high_fever = 0;
    int sweating = 0;
    int headache = 0;
    int nausea = 0;
    int loss_of_appetite = 0;


    QSqlQuery qry;
    QList<QString> list;

    QList<QString> listOfSym;


    if(ui->skin_rash->isChecked()){
        skin_rash = 1;
        qry.prepare("SELECT prognosis FROM mytable WHERE skin_rash = 1");
        if(qry.exec()){
            while(qry.next()){
                list.append(qry.value(0).toString());
            }
        }
        listOfSym.append("skin_rash");
    }

    if(ui->chills->isChecked()){
        chills = 1;
        qry.prepare("SELECT prognosis FROM mytable WHERE chills = 1");
        if(qry.exec()){
            while(qry.next()){
                list.append(qry.value(0).toString());
            }
        }
        listOfSym.append("chills");
    }
    if(ui->vomiting->isChecked()){
        vomiting = 1;
        qry.prepare("SELECT prognosis FROM mytable WHERE vomiting = 1");
        if(qry.exec()){
            while(qry.next()){
                list.append(qry.value(0).toString());
            }
        }
        listOfSym.append("vomiting");
    }

    if(ui->fatigue->isChecked()){
        fatigue = 1;
        qry.prepare("SELECT prognosis FROM mytable WHERE fatigue = 1");
        if(qry.exec()){
            while(qry.next()){
                list.append(qry.value(0).toString());
            }
        }
        listOfSym.append("fatigue");
    }

    if(ui->cough->isChecked()){
        cough = 1;
        qry.prepare("SELECT prognosis FROM mytable WHERE cough = 1");
        if(qry.exec()){
            while(qry.next()){
                list.append(qry.value(0).toString());
            }
        }
        listOfSym.append("cough");
    }

    if(ui->high_fever->isChecked()){
        high_fever = 1;
        qry.prepare("SELECT prognosis FROM mytable WHERE high_fever = 1");
        if(qry.exec()){
            while(qry.next()){
                list.append(qry.value(0).toString());
            }
        }
        listOfSym.append("high_fever");
    }
    if(ui->sweating->isChecked()){
        sweating = 1;
        qry.prepare("SELECT prognosis FROM mytable WHERE sweating = 1");
        if(qry.exec()){
            while(qry.next()){
                list.append(qry.value(0).toString());
            }
        }
        listOfSym.append("sweating");
    }

    if(ui->headache->isChecked()){
        headache = 1;
        qry.prepare("SELECT prognosis FROM mytable WHERE headache = 1");
        if(qry.exec()){
            while(qry.next()){
                list.append(qry.value(0).toString());
            }
        }
        listOfSym.append("headache");
    }

    if(ui->nausea->isChecked()){
        nausea = 1;
        qry.prepare("SELECT prognosis FROM mytable WHERE nausea = 1");
        if(qry.exec()){
            while(qry.next()){
                list.append(qry.value(0).toString());
            }
        }
        listOfSym.append("nausea");
    }

    if(ui->loss_of_appetite->isChecked()){
        loss_of_appetite = 1;
        qry.prepare("SELECT prognosis FROM mytable WHERE loss_of_appetite = 1");
        if(qry.exec()){
            while(qry.next()){
                list.append(qry.value(0).toString());
            }
        }
        listOfSym.append("loss_of_appetite");
    }


    list.sort();
    qDebug() << list;

    for(int i = 0; i < list.length(); i++){
        int flag=false;

        for(int j = i+1; j < list.length(); j++){
            for(int k=0; k<list2.length();k++){
                if(list[i]==list2[k])
                    flag=true;
            }
            if(list[i] == list[j]){
                if(flag==false)
                    list2.append(list[i]);
            }
        }
    }

    qDebug() << list2;

    qry.prepare("SELECT * FROM mytable WHERE prognosis = :name");
    qry.bindValue(":name", list2[0]);

    if(qry.exec()){
        while(qry.next()){
            for(int c=0;c<130;c++){
                if(qry.value(c).toInt() == 1){

                    QSqlRecord rec = qry.record();
                    QString nameCol = rec.fieldName(c);

                    bool flag=true;
                    for(int i=0;i<listOfSym.length();i++){

                        if (nameCol==listOfSym[i]){
                            flag=false;
                        }

                    }
                    if(flag==true){
                        listOfSym2.append(nameCol);
                    }
                }

            }
        }
    }

    qDebug() << listOfSym2;


    qDebug() << "________________";
    qDebug()<<listOfSym2;
    qDebug()<< list2;
    //qDebug() << newlist;

    questions2 * q = new questions2();
    q->showNormal();

}
