#include "history.h"
#include "ui_history.h"
#include <QDebug>
#include <QPixmap>


history::history(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::history)
{
    ui->setupUi(this);

    QPixmap pix1("C:/SDF/RailwayManagementSystem/historyMenu.jpg");
    ui->label_pic->setPixmap(pix1.scaled(684,551 ,Qt::IgnoreAspectRatio));
}

history::~history()
{
    delete ui;
}

void history::on_searchTrain_clicked()
{
    close();
}

