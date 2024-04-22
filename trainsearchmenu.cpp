#include "trainsearchmenu.h"
#include "ui_trainsearchmenu.h"
#include <QPixmap>
#include "dialog.h"
#include <QMessageBox>


trainSearchMenu::trainSearchMenu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::trainSearchMenu)
{
    ui->setupUi(this);
    QPixmap pix("C:/SDF/RailwayManagementSystem/SEARCHTRAIN_BG.jpg");
    ui->label_pic->setPixmap(pix.scaled(671,535,Qt::KeepAspectRatio));

    mydb = QSqlDatabase::addDatabase("QSQLITE");
    QString dbPath = QDir::currentPath() + "/Database/logindb.db";

    mydb.setDatabaseName(dbPath);
    if (!mydb.open())
        ui->label_demo->setText("Failed !");
    else
        ui->label_demo->setText("Connected !");
}

trainSearchMenu::~trainSearchMenu()
{
    delete ui;
}

void trainSearchMenu::on_pushButton_clicked()
{
    close();
    Dialog dmenu;
    dmenu.setModal(true);
    dmenu.exec();
}


void trainSearchMenu::on_search_clicked()
{
    QString bd, dt;
    bd = ui->boarding->text();
    dt = ui->destination->text();

    if(!mydb.isOpen()){
        qDebug()<<"Unexpected error!";
        return;
    }

    QSqlQuery q1;
    if(q1.exec("SELECT * FROM trainsInfo WHERE destination = '" + dt + "' AND boarding = '" + bd + "'")) {
        int count = 0;
        while(q1.next()) {
            count++;
            QString trainID = q1.value(2).toString(); //  train ID is in the second column
            QString trainName = q1.value(3).toString(); //  train name is in the third column

            // Construct the message string
            QString message = QString("Train is Available\nTrain ID: %1\nTrain Name: %2").arg(trainID).arg(trainName);

            // Show message box with train information
            QMessageBox::information(this, "Train Found", message);
            close();
            Dialog dmenu;
            dmenu.setModal(true);
            dmenu.exec();
        }

        if(count == 0) {
            // ui->label_demo->setText("No Train Found");
            QMessageBox::information(this,
                                     "Train Not Found",
                                     QString("Train is Not Available !"));
            close();
            Dialog dmenu;
            dmenu.setModal(true);
            dmenu.exec();
        }
    } else {
        qDebug() << "Error executing query:" << q1.lastError().text();
    }

    }
//}

