#include "traincancelmenu.h"
#include "ui_traincancelmenu.h"
#include <QmessageBox>
#include <QPixmap>
#include <QtSql>
#include "dialog.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

trainCancelMenu::trainCancelMenu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::trainCancelMenu)
{
    ui->setupUi(this);
    QPixmap pix("C:/SDF/RailwayManagementSystem/TrainCancellationMenu_bg.jpg");
    ui->cm_label->setPixmap(pix.scaled(925,600,Qt::KeepAspectRatio));

    // QSqlDatabase  mydb=QSqlDatabase::addDatabase("QSQLITE");
    // mydb.setDatabaseName("C:/Users/Admin/Documents/GitHub/RailwayManagementSystem/Database/loginDb.db");



    mydb = QSqlDatabase::addDatabase("QSQLITE");
    QString dbPath = QDir::currentPath() + "/Database/logindb.db";
    mydb.setDatabaseName(dbPath);

    if(!mydb.open()){

        ui->status->setText("Failed to open the Database");
    }

    // else
    // {
    //     ui->status->setText("Connected Successfully");
    // }

}



trainCancelMenu::~trainCancelMenu()
{
    delete ui;
}

void trainCancelMenu::on_pushButton_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::critical(this, "Confirmation", "Are you sure you want to cancel the booking ?",QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::No){
        //    QApplication::quit();
        //   ui->setupUi(this);
        //  MainWindow *mainWindow = new MainWindow();
    }
    else{
        close();
        QMessageBox::StandardButton reply1 = QMessageBox::information(this, "Cancelled", "Ticket Cancelled Successfully !", QMessageBox::Ok);
        if(reply1 == QMessageBox::Ok){
            close();
        }
    }
}


void trainCancelMenu::on_CancelButton_clicked()
{
    QString usernames;
    usernames = ui->username->text();

    QString id;
    id = ui->bookingId->text();

    QSqlQuery query;
    query.prepare("DELETE FROM bookings WHERE bookingId = :v1 and username = :v2;");
    query.bindValue(":v1", id);
    query.bindValue(":v2", usernames);

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    if(query.numRowsAffected() > 0)
    {
        qDebug() << "Deleted successfully";
        QMessageBox::information(this,
                                 "Cancellation Successful",
                                 QString("Your Booking is Cancelled Successfully !"));
        close();
        Dialog dmenu;
        dmenu.setModal(true);
        dmenu.exec();
    }

    else{
        qDebug() << "No Booking Found !";
        QMessageBox::information(this,
                                 "Cancellation Failed",
                                 QString("Your Booking can not be Cancelled !\nNo such record found !"));

        close();
        Dialog dmenu;
        dmenu.setModal(true);
        dmenu.exec();
    }
}

void trainCancelMenu::on_GoBackButton_clicked()
{
    close();
    Dialog dmenu;
    dmenu.setModal(true);
    dmenu.exec();
}


void trainCancelMenu::on_ChooseButton_currentTextChanged(const QString &arg1)
{

}

