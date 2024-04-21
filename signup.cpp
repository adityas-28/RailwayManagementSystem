#include "signup.h"
#include "ui_signup.h"
#include <QPixmap>
#include "mainwindow.h"
#include <QMessageBox>

SignUp::SignUp(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SignUp)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Aditya Singh/Documents/GitHub/RailwayManagementSystem/signup_bg.jpg");
    ui->label_pic->setPixmap(pix.scaled(781,591,Qt::IgnoreAspectRatio));

    mydb = QSqlDatabase::addDatabase("QSQLITE");

    QString dbPath = QDir::currentPath() + "/Database/logindb.db";
    mydb.setDatabaseName(dbPath);
    if (!mydb.open())
        ui->label_demo->setText("Failed !");
    // else
    //     ui->label_demo->setText("Connected !");
}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_pushButton_clicked()
{
    if (!mydb.isOpen()) {
        qDebug() << "Unexpected error: Database is not open!";
        return;
    }

    QSqlQuery q1;
    q1.prepare("INSERT INTO userinfo (username, password) VALUES (:username, :password)");
    QString inputUname = ui->uname->text();
    QString inputPswd = ui->pswd->text();
    q1.bindValue(":username", inputUname);
    q1.bindValue(":password", inputPswd);

    if (q1.exec()) {
        // Query executed successfully
        qDebug() << "Insertion into 'userinfo' table successful";
        close();

        // Show a QMessageBox to inform the user
        QMessageBox::information(this, "Success", "User Created Successfully !");


        // mainWindow->show();
      //  MainWindow loginWindow;
        MainWindow *loginWindow = new MainWindow();
        loginWindow->show();


     //   MainWindow xmenu;

    }
    else {
        // Query execution failed
        qDebug() << "Error inserting data into 'userinfo' table:" << q1.lastError().text();
        close();
    }
    //close();

}



void SignUp::on_pushButton_2_clicked()
{
    close();
    MainWindow *loginWindow = new MainWindow();
    loginWindow->show();

}

