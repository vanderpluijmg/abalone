TEMPLATE = subdirs
SUBDIRS += \
    src/abalonecore \
    src/tui

# Note that the / was replaced by - int the target name
src-tui.depends = src/abalonecore

OTHER_FILES += config.pri
