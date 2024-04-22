#ifndef TRAINCANCELMENU_H
#define TRAINCANCELMENU_H
#include <QSqlDatabase>
#include <QDebug>

#include <QDialog>

namespace Ui {
class trainCancelMenu;
}

class trainCancelMenu : public QDialog
{
    Q_OBJECT

public:
    explicit trainCancelMenu(QWidget *parent = nullptr);
    ~trainCancelMenu();

private slots:
    void on_pushButton_clicked();

    void on_CancelButton_clicked();

    void on_GoBackButton_clicked();

    void on_ChooseButton_currentTextChanged(const QString &arg1);

private:
    Ui::trainCancelMenu *ui;
    QSqlDatabase mydb;
};

#endif // TRAINCANCELMENU_H
