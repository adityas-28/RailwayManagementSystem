#include "book_a_train.h"
#include "ui_book_a_train.h"

BOOK_A_TRAIN::BOOK_A_TRAIN(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Book_Train)
{
    ui->setupUi(this);
}

BOOK_A_TRAIN::~BOOK_A_TRAIN()
{
    delete ui;
}
