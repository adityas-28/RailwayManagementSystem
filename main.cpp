#include "mainwindow.h"
#include "book_a_train.h"
#include "myapp.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);


    BOOK_A_TRAIN bookTrainDialog;
    bookTrainDialog.exec(); // or bookTrainDialog.show() if you want it non-modal

    MyApp myAppWidget;
    myAppWidget.show();

    return app.exec();
}
