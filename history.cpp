#include "history.h"
#include "ui_history.h"
#include <QDebug>
#include <QPixmap>
#include "dialog.h"
#include <QtSql>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>


history::history(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::history)
{
    ui->setupUi(this);

    QPixmap pix1("C:/SDF/RailwayManagementSystem/historyMenu.jpg");
    ui->label_pic->setPixmap(pix1.scaled(684,551 ,Qt::IgnoreAspectRatio));
}

history::~history()
{
    delete ui;
}

void history::on_searchTrain_clicked()
{
    close();
    Dialog dmenu;
    dmenu.setModal(true);
    dmenu.exec();
}


void history::on_pushButton_clicked()
{
    ui->bd->clear();
    ui->dt->clear();
    ui->cl->clear();
    ui->id->clear();

    ui->id->clear();
    ui->id_2->clear();
    ui->id_3->clear();

    ui->boarding->clear();
    ui->boarding_2->clear();
    ui->boarding_3->clear();

    ui->destination->clear();
    ui->destination_2->clear();
    ui->destination_3->clear();

    ui->arrow_1->clear();
    ui->arrow_2->clear();
    ui->arrow_3->clear();

    ui->class_1->clear();
    ui->class_2->clear();
    ui->class_3->clear();

    QString usernames = ui->username->text();

    QSqlQuery query;
    query.prepare("SELECT * FROM bookings WHERE username = :v1;");
    query.bindValue(":v1", usernames);

    if (!query.exec()) {
        qDebug() << "Error executing query : " << query.lastError().text();
        return;
    }

    int bookingCount = 0;
    while (query.next() && bookingCount < 3) {
        QString boarding = query.value(3).toString();
        QString destination = query.value(4).toString();
        QString class_0 = query.value(5).toString();
        QString id = query.value(1).toString();


        ui->bd->setText("Boarding");
        ui->dt->setText("Destination");
        ui->cl->setText("Class");
        ui->idd->setText("Booking Id");


        switch (bookingCount) {

        case 0:
            ui->boarding->setText(boarding);
            ui->destination->setText(destination);
            ui->class_1->setText(class_0);
            ui->arrow_1->setText("->");
            ui->id->setText(id);
            break;

        case 1:
            ui->boarding_2->setText(boarding);
            ui->destination_2->setText(destination);
            ui->class_2->setText(class_0);
            ui->arrow_2->setText("->");
            ui->id_2->setText(id);
            break;

        case 2:
            ui->boarding_3->setText(boarding);
            ui->destination_3->setText(destination);
            ui->class_3->setText(class_0);
            ui->arrow_3->setText("->");
            ui->id_3->setText(id);
            break;

        default:
            break;
        }

        bookingCount++;
    }

    if (bookingCount == 0) {

        qDebug() << "No booking found for username:" << usernames;
        ui->boarding->clear();
        QMessageBox::information(this,
                                 "No Record Found !",
                                 QString("No such record found !"));
        close();
        Dialog dmenu;
        dmenu.setModal(true);
        dmenu.exec();
    }
}


