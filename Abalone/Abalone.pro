TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Main.cpp \
        abapro.cpp \
        ball.cpp \
        board.cpp \
        direction.cpp \
        game.cpp \
        hexagon.cpp \
        player.cpp \
        position.cpp

HEADERS += \
    abapro.h \
    ball.h \
    board.h \
    direction.h \
    game.h \
    hexagon.h \
    player.h \
    position.h
