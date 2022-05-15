TEMPLATE = lib

QT += core widgets
TARGET = UiManager

DEFINES += Libs_PLUGIN_LIBRARY
include($$PWD/../../global_compile.pri)

#INCLUDEPATH += $$PWD/../../plugin

SOURCES += \
    utils/UiHelper.cpp

HEADERS += \
    utils/UiHelper.h
