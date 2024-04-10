#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ptrbooktrain=new BOOK_A_TRAIN();
}

MainWindow::~MainWindow()
{
    delete ptrbooktrain;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ptrbooktrain->show();
}

