QT += serialbus widgets

TARGET = can
TEMPLATE = app

SOURCES += \
    bitratebox.cpp \
    connectdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    sendframebox.cpp \
    logger.cpp \
    dataexplore.cpp

HEADERS += \
    bitratebox.h \
    connectdialog.h \
    mainwindow.h \
    sendframebox.h \
    logger.h \
    dataexplore.h

FORMS   += mainwindow.ui \
    connectdialog.ui \
    sendframebox.ui

RESOURCES += can.qrc

target.path = $$[QT_INSTALL_EXAMPLES]/serialbus/can
INSTALLS += target
