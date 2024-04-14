#ifndef TRAINCANCELMENU_H
#define TRAINCANCELMENU_H

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

private:
    Ui::trainCancelMenu *ui;
};

#endif // TRAINCANCELMENU_H
