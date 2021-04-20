TEMPLATE = app
CONFIG -= qt
CONFIG -= app_bundle
CONFIG += console

win32-g++* {
    # Work around "too many sections" bug in MinGW.
    # This comes from the catch2 header only file being gargantuan.
    QMAKE_CXXFLAGS += -Wa,-mbig-obj
}

include(../config.pri)

SOURCES +=     main.cpp\
               tst_position.cpp
