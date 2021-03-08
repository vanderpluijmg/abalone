TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ball.cpp \
        board.cpp \
        direction.cpp \
        game.cpp \
        hexagon.cpp \
        main.cpp \
        player.cpp \
        position.cpp

HEADERS += \
    ball.h \
    board.h \
    direction.h \
    game.h \
    hexagon.h \
    player.h \
    position.h
