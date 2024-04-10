#include "myapp.h"

MyApp::MyApp(QWidget *parent) : QWidget(parent) {
    setupUi();
    createDatabaseConnection();
    fetchDataFromDatabase();
}

void MyApp::setupUi() {
    layout = new QVBoxLayout(this);

    searchLineEdit = new QLineEdit(this);
    layout->addWidget(searchLineEdit);

    searchButton = new QPushButton("Search", this);
    layout->addWidget(searchButton);
    connect(searchButton, &QPushButton::clicked, this, &MyApp::filterData);

    resultLabel = new QLabel(this);
    layout->addWidget(resultLabel);

    model = new QStringListModel(this);
    listView = new QListView(this);
    listView->setModel(model);
    layout->addWidget(listView);
}

void MyApp::createDatabaseConnection() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:\Users\Dishi\Desktop\RMS_database.db");
    if (!db.open()) {
        qDebug() << "Error: Failed to connect to database." << db.lastError().text();
    }
}

void MyApp::fetchDataFromDatabase() {
    QSqlQuery query;
    if (query.exec("SELECT * FROM BOOKING")) {
        while (query.next()) {
            QString item = query.value(0).toString();
            data << item;
        }
    } else {
        qDebug() << "Error: Failed to execute query." << query.lastError().text();
    }
}

void MyApp::filterData() {
    QString searchText = searchLineEdit->text();
    QStringList filteredData;

    for (const QString &item : data) {
        if (item.contains(searchText, Qt::CaseInsensitive)) {
            filteredData << item;
        }
    }

    model->setStringList(filteredData);

    if (filteredData.isEmpty()) {
        resultLabel->setText("No matching results found.");
    } else {
        resultLabel->setText(QString("Showing %1 matching result(s).").arg(filteredData.size()));
    }
}

