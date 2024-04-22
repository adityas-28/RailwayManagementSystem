#include "train_options.h"
#include "ui_train_options.h"

Train_options::Train_options(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Train_options)
{
    ui->setupUi(this);
}

Train_options::~Train_options()
{
    delete ui;
}
