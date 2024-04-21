#include "dialog.h"
#include "trainbookingmenu.h"
#include "traincancelmenu.h"
#include "ui_dialog.h"
#include <QPixmap>
#include "dialog.h"
#include <QDebug>
#include "history.h"
#include "mainwindow.h"
// #include "qdir.h"


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    // QPixmap pix1(QDir::currentPath() + "/dialogWindow_bg.jpg");
    QPixmap pix1("C:/SDF/RailwayManagementSystem/dialogWindow_bg.jpg");


    ui->pic_main->setPixmap(pix1.scaled(801,571 ,Qt::IgnoreAspectRatio));
}


Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_trainBooking_clicked()
{
    close();
    trainBooking bmenu;
    bmenu.setModal(true);
    bmenu.exec();
}


void Dialog::on_trainCancellation_clicked()
{
    close();
    trainCancelMenu dmenu;
    dmenu.setModal(true);
    dmenu.exec();
}


void Dialog::on_trans_History_clicked()
{
    close();
    history emenu;
    emenu.setModal(true);
    emenu.exec();
}


void Dialog::on_pushButton_clicked()
{
    close();
    MainWindow *loginWindow = new MainWindow();
    loginWindow->show();
}

