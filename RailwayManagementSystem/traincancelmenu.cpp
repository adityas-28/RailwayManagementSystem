#include "traincancelmenu.h"
#include "ui_traincancelmenu.h"
#include <QmessageBox>

trainCancelMenu::trainCancelMenu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::trainCancelMenu)
{
    ui->setupUi(this);
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

