#ifndef TRAINSEARCHMENU_H
#define TRAINSEARCHMENU_H
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>

#include <QDialog>

namespace Ui {
class trainSearchMenu;
}

class trainSearchMenu : public QDialog
{
    Q_OBJECT

public:
    explicit trainSearchMenu(QWidget *parent = nullptr);
    ~trainSearchMenu();

private slots:
    void on_pushButton_clicked();

    void on_search_clicked();

private:
    Ui::trainSearchMenu *ui;
    QSqlDatabase mydb;
};

#endif // TRAINSEARCHMENU_H
