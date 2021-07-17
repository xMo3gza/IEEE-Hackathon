#ifndef QUESTIONS_H
#define QUESTIONS_H

#include <QMainWindow>

namespace Ui {
class questions;
}

class questions : public QMainWindow
{
    Q_OBJECT

public:
    explicit questions(QWidget *parent = nullptr);

    static QList<QString> listOfSym2;
    static QList<QString> list2;
    ~questions();

private slots:
    void on_pushButton_clicked();

private:
    Ui::questions *ui;
};

#endif // QUESTIONS_H
