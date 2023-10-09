QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    inputbtnwidget.cpp \
    main.cpp \
    maingame.cpp \
    messages_dialog.cpp \
    selectlevel.cpp \
    showscores.cpp \
    sudoku.cpp \
    sudokugenerator.cpp

HEADERS += \
    gameData.h \
    inputbtnwidget.h \
    maingame.h \
    messages_dialog.h \
    selectlevel.h \
    showscores.h \
    sudoku.h \
    sudokugenerator.h

FORMS += \
    maingame.ui \
    messages_dialog.ui \
    selectlevel.ui \
    showscores.ui \
    sudoku.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DESTDIR = $${PWD}/builds
OBJECTS_DIR = $${DESTDIR}/.obj
MOC_DIR = $${DESTDIR}/.mocs
RCC_DIR = $${DESTDIR}/.rcc
UI_DIR =  $${DESTDIR}/.ui
