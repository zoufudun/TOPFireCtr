QT       += core gui xml

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
<<<<<<< HEAD
    componentmanager.cpp \
    dimodule.cpp \
    dimoduleconfigdialog.cpp \
    domodule.cpp \
    domoduleconfigdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    projectmanager.cpp \
    thememanager.cpp

HEADERS += \
    componentmanager.h \
    dimodule.h \
    dimoduleconfigdialog.h \
    domodule.h \
    domoduleconfigdialog.h \
    mainwindow.h \
    projectmanager.h \
    thememanager.h
=======
    main.cpp \
    mainwindow.cpp \
    projectmanager.cpp \
    componentmanager.cpp

HEADERS += \
    componentmanager.h \
    mainwindow.h \
    projectmanager.h \
    projectmanager.h \
    componentmanager.h
>>>>>>> 9bd960c (V0.1)

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

<<<<<<< HEAD
RESOURCES += \
<<<<<<< HEAD
    resources.qrc

OTHER_FILES += \
    themes/default.qss \
    themes/atom_one.qss \
    themes/solarized_light.qss

CODECFORTR = UTF-8
CODECFORSRC = UTF-8
=======
    resources.qrc
>>>>>>> 9bd960c (V0.1)
=======
RESOURCES += resources.qrc
>>>>>>> d0afa2c (组件实现双击添加)
