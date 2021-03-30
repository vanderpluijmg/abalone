TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -pedantic-errors

HEADERS += \
    Model/abapro.h \
    Model/board.h \
    Model/color.hpp \
    Model/direction.h \
    Model/game.hpp \
    Model/hexagon.hpp \
    Model/player.h \
    Model/position.hpp

SOURCES += \
    Model/Main.cpp \
    Model/abapro.cpp \
    Model/board.cpp \
    Model/direction.cpp \
    Model/player.cpp


