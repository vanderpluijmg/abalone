TEMPLATE = subdirs
SUBDIRS += \
    src/abalonecore \
    src/tui \
    src/gui \
    unitTest

# Note that the / was replaced by - in the target name
src-tui.depends = src/abalonecore
src-gui.depends = src/abalonecore
test.depends = src/abalonecore

#tests.depends = src/abalonecore
OTHER_FILES += config.pri\
                Doxyfile
