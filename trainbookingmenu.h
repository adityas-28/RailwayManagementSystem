#ifndef TRAINBOOKINGMENU_H
#define TRAINBOOKINGMENU_H

#include <QDialog>

namespace Ui {
class trainBooking;
}

class trainBooking : public QDialog
{
    Q_OBJECT

public:
    explicit trainBooking(QWidget *parent = nullptr);
    ~trainBooking();

private:
    Ui::trainBooking *ui;
};

#endif // TRAINBOOKINGMENU_H