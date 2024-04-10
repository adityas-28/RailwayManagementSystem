#ifndef BOOK_A_TRAIN_H
#define BOOK_A_TRAIN_H

#include <QDialog>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QStringListModel>
#include <QListView>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

namespace Ui {
class Book_Train;
}

class BOOK_A_TRAIN : public QDialog
{
    Q_OBJECT

public:
    explicit BOOK_A_TRAIN(QWidget *parent = nullptr);
    ~BOOK_A_TRAIN();

private:
    Ui::Book_Train *ui;
};

#endif // BOOK_A_TRAIN_H
