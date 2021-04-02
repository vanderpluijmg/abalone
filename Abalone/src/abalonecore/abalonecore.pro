CONFIG -= qt

TEMPLATE = lib
CONFIG += staticlib

include(../../config.pri)

HEADERS += \
    abalonecore.h \
    abapro.h \
    board.h \
    color.hpp \
    direction.h \
    hexagon.hpp \
    player.h \
    position.hpp \
    game.h \

SOURCES += \
    abalonecore.cpp \
    abapro.cpp \
    board.cpp \
    direction.cpp \
    player.cpp \
    game.cpp \
    
DISTFILES += \
	abalonecore.pri


