QT -= gui

CONFIG += c++11
CONFIG -= app_bundle

LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

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
        main.cpp \
    world.cpp \
    entity.cpp \
    projectile.cpp \
    enemy.cpp \
    player.cpp \
    tower.cpp \
    texturemanager.cpp \
    spawn.cpp \
    map.cpp \
    item.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    world.h \
    entity.h \
    projectile.h \
    enemy.h \
    player.h \
    tower.h \
    includes.h \
    texturemanager.h \
    spawn.h \
    map.h \
    item.h
