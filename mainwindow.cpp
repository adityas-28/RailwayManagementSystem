#include "mainwindow.h"
#include <QApplication>
#include <QMainWindow>
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QMessageBox>
#include <QDebug>
#include "dialog.h"
#include "signup.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // qDebug()<<"hello !";
    mydb = QSqlDatabase::addDatabase("QSQLITE");

    // QString dbPath = QDir::currentPath() + "/Database/logindb.db";
    QString dbPath = "C:/Users/Admin/Documents/GitHub/RailwayManagementSystem2/Database/loginDb.db";
    mydb.setDatabaseName(dbPath);
    if (!mydb.open())
        ui->label_demo->setText("Failed !");
    // else
    //     ui->label_demo->setText("Connected !");

    // QPixmap pix("C:/Users/Aditya Singh/Pictures/RMS_Qt/irctc_pic.jpg");
    // ui->pic_label->setPixmap(pix.scaled(200,200,Qt::KeepAspectRatio));f
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_enter_clicked()
{
  /*  this->hide();
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Title1", "Are you sure you want to login ?",QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::No){
        QApplication::quit();
     //   ui->setupUi(this);
        MainWindow *mainWindow = new MainWindow();
        mainWindow->show();

    }
    else{
     //   qDebug() << "You clicked Yes";
        Dialog dmenu;
        dmenu.setModal(true);
        dmenu.exec();
    }*/

    QString username, password;
    username = ui->username->text();
    password = ui->password->text();

    if(!mydb.isOpen()){
        qDebug()<<"Unexpected error!";
        return;
    }

    QSqlQuery q1;
    if(q1.exec("select * from userinfo where username = '"+username +"' and password = '"+password +"'")){
        int count = 0;
        while(q1.next()){
            count++;
        }
        if(count>0){
            ui->label_demo->setText("Correct Username and Password !");
            this->hide();
            QMessageBox::StandardButton reply = QMessageBox::question(this, "Title1", "Are you sure you want to login ?",QMessageBox::Yes | QMessageBox::No);
            if(reply == QMessageBox::No){
               // QApplication::quit();
                //   ui->setupUi(this);
                MainWindow *mainWindow = new MainWindow();
                mainWindow->show();

            }
            else{
                //   qDebug() << "You clicked Yes";
                this->hide();
                Dialog dmenu;
                dmenu.setModal(true);
                dmenu.exec();
            }
        }
        else
            ui->label_demo->setText("Incorrect Username and Password !");
    }

}


void MainWindow::on_cancel_clicked()
{
    close();
}


void MainWindow::on_signUp_clicked()
{
   this->hide();

    SignUp xmenu;
    xmenu.setModal(true);
    xmenu.exec();
}

