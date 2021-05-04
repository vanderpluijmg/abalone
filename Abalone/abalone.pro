TEMPLATE = subdirs
SUBDIRS += \
    src/abalonecore \
    src/tui \
    gui \

 #   tests

# Note that the / was replaced by - in the target name
src-tui.depends = src/abalonecore
#tests.depends = src/abalonecore
OTHER_FILES += config.pri\
                Doxyfile
