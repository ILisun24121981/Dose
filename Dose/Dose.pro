QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controller.cpp \
    data_model.cpp \
    logger.cpp \
    login_processor.cpp \
    main.cpp \
    login_form.cpp \
    mainwindow.cpp \
    mainwindow_processor.cpp \
    processor.cpp \
    repor_manager.cpp \
    settings.cpp \
    txt_logger.cpp \
    txt_login_processor.cpp \
    txt_processor.cpp

HEADERS += \
    controller.h \
    data_model.h \
    logger.h \
    login_form.h \
    login_processor.h \
    mainwindow.h \
    mainwindow_processor.h \
    processor.h \
    repor_manager.h \
    settings.h \
    txt_logger.h \
    txt_login_processor.h \
    txt_processor.h

FORMS += \
    login_form.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
