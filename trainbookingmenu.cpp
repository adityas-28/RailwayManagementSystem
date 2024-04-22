#include "trainbookingmenu.h"
#include "ui_trainbookingmenu.h"
#include "mainwindow.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <train_options.h>
#include "dialog.h"
#include <QDebug>
#include <string>

QString fromLocation, toLocation,trainclass;

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
    // else
    //     ui->label_demo->setText("Connected !");

    // QSqlQuery query;
    // query.prepare("SELECT boarding FROM trainsInfo");
    // query.exec();

    // ui->comboBox_1->addItem(query.first());
    // for(int i = 0; i < 5; i++){
    // ui->comboBox_1->addItem(query.next());
    // }

    ui->comboBox_1->clear();
    ui->comboBox_2->clear();

    QSqlQuery query, query2;
    query.prepare("SELECT Boarding FROM trainsInfo");
    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    while (query.next()) {
        //qDebug()<<query.value(0).toString();
        QString loc1 = query.value(0).toString();
        ui->comboBox_1->addItem(loc1);
    }

    query.prepare("SELECT Destination FROM trainsInfo");
    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    while (query.next()) {
        // qDebug()<<query.value(0).toString();
        QString loc2 = query.value(0).toString();
        ui->comboBox_2->addItem(loc2);

        // QString comboBox_1 = ;
    }


    QSqlQuery query3;
    query3.prepare("SELECT * from Bookings");

    int count = 0;
    while(query3.next()){
        count++;
        qDebug() << "\n\n\n" << count << "\n";
    }
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

void trainBooking::on_pushButton_clicked()
{

    QString usernames;
    usernames = ui->username->toPlainText();

    QSqlQuery query;
    query.prepare("SELECT * from Bookings");

    int count = 0;
    while(query.next()){
        count++;
        qDebug() << count;
    }


    std::string a = "a00";
    a = a+std::to_string(count);
    qDebug()<<a;




    QSqlQuery q1;
    q1.prepare("INSERT INTO Bookings (username, Sno) VALUES (:v1, :v2)");
    q1.bindValue(":v1", usernames);
    q1.bindValue(":v2", count);

    if (!q1.exec()) {
        qDebug() << "Error executing query:" << q1.lastError().text();
        qDebug() << "Query:" << q1.lastQuery();
    } else {
        qDebug() << "Data inserted successfully!";
        Train_options train_op;
        train_op.setModal(true);
        train_op.exec();
    }
}



void trainBooking::on_comboBox_1_currentTextChanged(const QString &arg1)
{
    fromLocation = arg1;
}


void trainBooking::on_comboBox_2_currentTextChanged(const QString &arg1)
{
    toLocation=arg1;
}


void trainBooking::on_textEdit_textChanged()
{
    QTextEdit textEdit;
    trainclass=textEdit.toPlainText();
    qDebug() << trainclass;
}

