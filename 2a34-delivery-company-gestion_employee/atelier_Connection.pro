#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23
#
#-------------------------------------------------




win32:CONFIG(release, debug|release): {
    # Specify the library paths
    LIBS += -L$$PWD/../../../vcpkg/vcpkg/installed/x64-windows/lib/ -lcrypto -lssl -lcurl

    # Specify the include paths
    INCLUDEPATH += $$PWD/../../../vcpkg/vcpkg/installed/x64-windows/include
    DEPENDPATH += $$PWD/../../../vcpkg/vcpkg/installed/x64-windows/include

}
QT       += core gui sql network multimedia multimediawidgets charts printsupport widgets axcontainer \
    quick

CONFIG += c++11
QT       += core gui  serialport
QT       += core gui sql
QT += core gui sql printsupport
QT += charts
QT += network
QT += network widgets




#INCLUDEPATH += /chemin/vers/les/fichiers/den-tête/de/libcurl



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Atelier_Connexion
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += console

SOURCES += \
    BarChartItem.cpp \
    Employee.cpp \
    acces.cpp \
    arduino.cpp \
    chatbotwindow.cpp \
        main.cpp \
        mainwindow.cpp \
    connection.cpp

HEADERS += \
    BarChartItem.h \
    Employee.h \
    acces.h \
    arduino.h \
    chatbotwindow.h \
        mainwindow.h \
    connection.h

FORMS += \
        acces.ui \
        chatbotwindow.ui \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=








