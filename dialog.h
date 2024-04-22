#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_trainBooking_clicked();

    void on_trainCancellation_clicked();

    void on_trans_History_clicked();

    void on_pushButton_clicked();

    void on_searchTrain_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
