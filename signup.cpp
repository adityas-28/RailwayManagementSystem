#include "signup.h"
#include "ui_signup.h"
#include <QPixmap>

SignUp::SignUp(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SignUp)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Aditya Singh/Desktop/signup_bg.jpg");
    ui->label_pic->setPixmap(pix.scaled(771,591,Qt::IgnoreAspectRatio));
}

SignUp::~SignUp()
{
    delete ui;
}
