QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    gui/GScene.cpp \
    gui/GSprite.cpp \
    gui/GameGUI.cpp \
    logic/Block.cpp \
    logic/Bullet.cpp \
    logic/Enemy.cpp \
    logic/GObject.cpp \
    logic/Game.cpp \
    logic/Player.cpp \
    logic/main.cpp \
    main.cpp \

HEADERS += \
    gui/GScene.h \
    gui/GSprite.h \
    gui/GameGUI.h \
    logic/Block.h \
    logic/Bullet.h \
    logic/Constants.h \
    logic/Enemy.h \
    logic/GObject.h \
    logic/Game.h \
    logic/IMovable.h \
    logic/IShootable.h \
    logic/Player.h

FORMS += \
    gui/gamegui.ui

CONFIG += lrelease

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    gui/images.qrc \

DISTFILES +=
