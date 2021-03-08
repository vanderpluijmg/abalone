TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ball.cpp \
        board.cpp \
        direction.cpp \
        hexagon.cpp \
        main.cpp \
        position.cpp

HEADERS += \
    ball.h \
    board.h \
    direction.h \
    hexagon.h \
    position.h
