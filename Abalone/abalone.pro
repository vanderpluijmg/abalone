TEMPLATE = subdirs
SUBDIRS += \
    src/abalonecore \
    src/tui \
<<<<<<< HEAD
=======
    gui \

 #   tests
>>>>>>> 9634c804e2244ecffdacd0dca2a37a82da2415a6

# Note that the / was replaced by - in the target name
src-tui.depends = src/abalonecore
#tests.depends = src/abalonecore
OTHER_FILES += config.pri\
                Doxyfile
