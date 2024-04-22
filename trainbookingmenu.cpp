#include "trainbookingmenu.h"
#include "ui_trainbookingmenu.h"
#include "mainwindow.h"
#include <QSqlQuery>
#include <QSqlError>
#include "dialog.h"

trainBooking::trainBooking(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::trainBooking)
{
    ui->setupUi(this);
    mydb = QSqlDatabase::addDatabase("QSQLITE");

    QString dbPath = QDir::currentPath() + "/Database/logindb.db";
    mydb.setDatabaseName(dbPath);
    if (!mydb.open())
        ui->label_demo->setText("Failed !");
    else
        ui->label_demo->setText("Connected !");

    // QSqlQuery query;
    // query.prepare("SELECT boarding FROM trainsInfo");
    // query.exec();

    // ui->comboBox_1->addItem(query.first());
    // for(int i = 0; i < 5; i++){
    // ui->comboBox_1->addItem(query.next());
    // }
}

trainBooking::~trainBooking()
{
    delete ui;
}

void trainBooking::on_comboBox_currentTextChanged()
{
    ui->comboBox_1->clear();

/*    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT boarding FROM trainsInfo");
    ui->comboBox_1->setModel(model);
*/
    /*
QSqlQuery query;
    query.exec(QString("SELECT boarding FROM trainsInfo"));
if (query.next())
{
    QString loc1 = query.value(0).toString();
    ui->comboBox_1->addItem(loc1);
} else {
    qDebug() << "SqLite error:" << query.lastError().text() << ", SqLite error code:" << query.lastError().text();
}
*/

    QSqlQuery query("SELECT boarding FROM trainsInfo", mydb);
    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

   while (query.next()) {
        QString loc1 = query.value(0).toString();
        ui->comboBox_1->addItem(loc1);
   }

    // query.first();
   // query.exec(QString("SELECT boarding FROM booking"));

   // if (query.next())
    // {
    // use it
  //  } else {
      //  qDebug() << "SqLite error:" << query.lastError().text() << ", SqLite error code:" << query.lastError().number();
  //  }
    // else{
    //     qDebug() << "Error executing query:" << query.lastError().text();
    //        return;
    // }
    // QSqlQuery query("SELECT boarding FROM booking",mydb);
    // if (!query.exec()) {
    //     qDebug() << "Error executing query:" << query.lastError().text();
    //     return;
    // }
    // while (query.next()) {
    //     QString cityName = query.value(0).toString();
    //     ui->comboBox->addItem(cityName);
    // }
// }



}

void trainBooking::on_pushButton_2_clicked()
{
    close();
    Dialog dmenu;
    dmenu.setModal(true);
    dmenu.exec();

}
