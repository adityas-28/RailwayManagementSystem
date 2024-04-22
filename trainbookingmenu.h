#ifndef TRAINBOOKINGMENU_H
#define TRAINBOOKINGMENU_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QtDebug>
#include <QFileInfo>
#include "mainwindow.h"


namespace Ui {
class trainBooking;
}

class trainBooking : public QDialog
{
    Q_OBJECT

public:
    explicit trainBooking(QWidget *parent = nullptr);
    ~trainBooking();

private slots:
    void on_comboBox_currentTextChanged();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_comboBox_1_currentTextChanged(const QString &arg1);

    void on_comboBox_2_currentTextChanged(const QString &arg1);

    void on_textEdit_textChanged();

private:
    Ui::trainBooking *ui;
    QSqlDatabase mydb;
};

#endif // TRAINBOOKINGMENU_H
