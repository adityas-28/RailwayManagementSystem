#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase> //
#include <QtDebug>
#include <QFileInfo>
#include "mainwindow.h"

namespace Ui {
class SignUp;
}

class SignUp : public QDialog
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::SignUp *ui;
    QSqlDatabase mydb;
};

#endif // SIGNUP_H
