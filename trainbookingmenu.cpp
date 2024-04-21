#include "trainbookingmenu.h"
#include "ui_trainbookingmenu.h"
#include "mainwindow.h"
#include <QSqlQuery>
#include <QSqlError>

trainBooking::trainBooking(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::trainBooking)
{
    ui->setupUi(this);
}

trainBooking::~trainBooking()
{
    delete ui;
}

void trainBooking::on_comboBox_currentTextChanged()
{
       QSqlQuery query("SELECT boarding FROM booking",mydb);
    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }
    while (query.next()) {
        QString cityName = query.value(0).toString();
        ui->comboBox->addItem(cityName);
    }
}

