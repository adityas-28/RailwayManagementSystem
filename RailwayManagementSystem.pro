QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialog.cpp \
    history.cpp \
    main.cpp \
    mainwindow.cpp \
    signup.cpp \
    train_options.cpp \
    trainbookingmenu.cpp \
    traincancelmenu.cpp \
    trainsearchmenu.cpp

HEADERS += \
    dialog.h \
    history.h \
    mainwindow.h \
    signup.h \
    train_options.h \
    trainbookingmenu.h \
    traincancelmenu.h \
    trainsearchmenu.h

FORMS += \
    dialog.ui \
    history.ui \
    mainwindow.ui \
    signup.ui \
    train_options.ui \
    trainbookingmenu.ui \
    traincancelmenu.ui \
    trainsearchmenu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Images.qrc
