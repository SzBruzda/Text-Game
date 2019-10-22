TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    game.cpp \
    character.cpp \
    blacksmith.cpp \
    tavern.cpp \
    enemy.cpp \
    battle.cpp

HEADERS += \
    game.h \
    character.h \
    blacksmith.h \
    tavern.h \
    enemy.h \
    battle.h
