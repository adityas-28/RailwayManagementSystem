#ifndef MYAPP_H
#define MYAPP_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QStringListModel>
#include <QListView>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

class MyApp : public QWidget {
    Q_OBJECT

public:
    MyApp(QWidget *parent = nullptr);

private:
    QVBoxLayout *layout;
    QLineEdit *searchLineEdit;
    QPushButton *searchButton;
    QLabel *resultLabel;
    QListView *listView;
    QStringListModel *model;
    QStringList data;

    void setupUi();
    void createDatabaseConnection();
    void fetchDataFromDatabase();

private slots:
    void filterData();
};

#endif // MYAPP_H

