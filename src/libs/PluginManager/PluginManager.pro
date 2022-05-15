TEMPLATE = lib
CONFIG += staticlib


QT += core widgets
TARGET = PluginManager

DEFINES += Libs_PLUGIN_LIBRARY
include($$PWD/../../global_compile.pri)

INCLUDEPATH += $$PWD/../../plugin

SOURCES += \
    LibraryPathSet.cpp \
    PluginManage.cpp \
    PluginSpec.cpp

HEADERS += \
    LibraryPathSet.h \
    PluginManage.h \
    PluginSpec.h
