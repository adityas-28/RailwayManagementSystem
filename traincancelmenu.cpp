#include "traincancelmenu.h"
#include "ui_traincancelmenu.h"
#include <QmessageBox>
#include <QPixmap>
#include <QtSql>
#include "dialog.h"

trainCancelMenu::trainCancelMenu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::trainCancelMenu)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Admin/Documents/GitHub/RailwayManagementSystem/cancelMenu_bg.jpg");
    ui->cm_label->setPixmap(pix.scaled(818,554,Qt::KeepAspectRatio));

    // QSqlDatabase  mydb=QSqlDatabase::addDatabase("QSQLITE");
    // mydb.setDatabaseName("C:/Users/Admin/Documents/GitHub/RailwayManagementSystem/Database/loginDb.db");


    mydb = QSqlDatabase::addDatabase("QSQLITE");
    QString dbPath = QDir::currentPath() + "/Database/logindb.db";
    mydb.setDatabaseName(dbPath);

    if(!mydb.open()){

        ui->status->setText("Failed to open the Database");
    }

    else
    {
        ui->status->setText("Connected Successfully");
    }

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


}


void trainCancelMenu::on_GoBackButton_clicked()
{
    close();
    Dialog dmenu;
    dmenu.setModal(true);
    dmenu.exec();
}

