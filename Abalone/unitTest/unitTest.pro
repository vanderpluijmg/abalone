TEMPLATE = app
QT += gui

win32-g++* {
    QMAKE_CXXFLAGS += -Wa,-mbig-obj
}

include (../config.pri)


#INCLUDEPATH += ../libs/

SOURCES +=     main.cpp     tst_model.cpp
