CONFIG += c++17

# This option is enabled by default on Windows, but not on Linux and macOS.
# This is unconsistent behavior that breaks our builds.
# Rather than overcompiling our qmake rules, let's disable this everywhere.
CONFIG -= debug_and_release debug_and_release_target

INCLUDEPATH += $${PWD}/libs/

#Or sharedlib
CORELIBMODE = staticlib

!equals(TARGET, abalonecore) {
	include($${PWD}/src/abalonecore/abalonecore.pri)
}

QMAKE_CXXFLAGS += -Wall -Wextra -pedantic
lessThan(QT_MAJOR_VERSION, 5) {
    error("Use Qt 5 or newer")
}

lessThan(QT_MINOR_VERSION, 12) {
    # Support for c++17 CONFIG option was added in Qt 5.12
    # Fall back on compiler option for older versions.
    QMAKE_CXXFLAGS += -std=c++17
}
