QT       += core gui
QT       += sql
QT       += svg
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
    GUI_level/buttonhoverwatcher.cpp \
    GUI_level/close_button.cpp \
    GUI_level/operator_editor.cpp \
    GUI_level/operator_editor_update.cpp \
    GUI_level/operator_tree.cpp \
    Storage_Level/connect_database.cpp \
    Storage_Level/country_storage.cpp \
    Storage_Level/manager_storage.cpp \
    Storage_Level/operator_storage.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    GUI_level/buttonhoverwatcher.h \
    GUI_level/close_button.h \
    GUI_level/operator_editor.h \
    GUI_level/operator_editor_update.h \
    GUI_level/operator_tree.h \
    Storage_Level/connect_database.h \
    Storage_Level/country_storage.h \
    Storage_Level/manager_storage.h \
    Storage_Level/operator_storage.h \
    mainwindow.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
