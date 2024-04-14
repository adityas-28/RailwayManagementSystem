#include "dialog.h"
#include "trainbookingmenu.h"
#include "traincancelmenu.h"
#include "ui_dialog.h"
#include <QPixmap>
#include "dialog.h"
#include <QDebug>


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QPixmap pix1("C:/Users/Aditya Singh/Pictures/RMS_Qt/irctc_pic2.jpg");
    ui->pic_main->setPixmap(pix1.scaled(750,500,Qt::IgnoreAspectRatio));
}


Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_trainBooking_clicked()
{
    trainBooking bmenu;
    bmenu.setModal(true);
    bmenu.exec();
}


void Dialog::on_trainCancellation_clicked()
{
    trainCancelMenu dmenu;
    dmenu.setModal(true);
    dmenu.exec();
}

