#ifndef QUESTIONS2_H
#define QUESTIONS2_H

#include <QMainWindow>

namespace Ui {
class questions2;
}

class questions2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit questions2(QWidget *parent = nullptr);
    QList<QString> newlist;
    ~questions2();

private slots:
    void on_pushButton_clicked();

private:
    Ui::questions2 *ui;
};

#endif // QUESTIONS2_H
