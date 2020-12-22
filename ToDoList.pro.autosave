QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CleanerComletedTasks.cpp \
    DatabaseConnector.cpp \
    ListChanger.cpp \
    MainWindow.cpp \
    QuickTaskWindow.cpp \
    SplashScreen.cpp \
    TaskWriteWindow.cpp \
    main.cpp

HEADERS += \
    CleanerComletedTasks.h \
    DatabaseConnector.h \
    ListChanger.h \
    MainWindow.h \
    QuickTaskWindow.h \
    SplashScreen.h \
    TaskWriteWindow.h

FORMS += \
    CleanerComletedTasks.ui \
    DatabaseConnector.ui \
    ListChanger.ui \
    MainWindow.ui \
    SplashScreen.ui \
    TaskWriteWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
