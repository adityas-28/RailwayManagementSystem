#ifndef TRAIN_OPTIONS_H
#define TRAIN_OPTIONS_H

#include <QDialog>

namespace Ui {
class Train_options;
}

class Train_options : public QDialog
{
    Q_OBJECT

public:
    explicit Train_options(QWidget *parent = nullptr);
    ~Train_options();

private:
    Ui::Train_options *ui;
};

#endif // TRAIN_OPTIONS_H
