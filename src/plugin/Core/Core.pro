QT += gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = lib
TARGET = Core
DEFINES += FlySnail_PLUGIN_LIBRARY
DEFINES += Core_Plugin
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
include($$PWD/../../global_compile.pri)
include($$PWD/../Global/Global.pri)
include($$PWD/Application/Application.pri)

SOURCES += \
    ui/MainWindow.cpp \
    Plugin.cpp

HEADERS += \
    ../Plugin.h \
    ui/MainWindow.h

FORMS += \
    ui/MainWindow.ui

INCLUDEPATH += \
    $$PWD/Application \
    $$PWD/../../libs/PluginManager \
    $$PWD/../../libs/UiManager


# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

RESOURCES +=

# copy config
#CONFIG += file_copies
#config_copy.files += $$PWD/../config/ui.ini
#config_copy.path += $$OUT_DIR/$${PlatForm}/$${ARCHITECTURE}/$${DebugOrRelease}/config
#COPIES += config_copy
