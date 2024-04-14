#include "trainbookingmenu.h"
#include "ui_trainbookingmenu.h"

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
