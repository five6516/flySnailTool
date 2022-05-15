INCLUDEPATH += \
    $$PWD \
    $$PWD/../

HEADERS += \
    $$PWD/Global.h \

SOURCES += \

SOURCE_DIR = $$PWD/../../..

#message($${SOURCE_DIR}/bin/$${PlatForm}/$${ARCHITECTURE}/$${DebugOrRelease})
LIBS+= -L$${SOURCE_DIR}/bin/$${PlatForm}/$${ARCHITECTURE}/$${DebugOrRelease} -lPluginManager -lUiManager

INCLUDEPATH+=$${SOURCE_DIR}/src/libs/PluginManager \
             $${SOURCE_DIR}/src/libs/UiManager

DEPENDPATH+=$${SOURCE_DIR}/src/libs/PluginManager \
            $${SOURCE_DIR}/src/libs/UiManager

contains(DEFINES, Tool_Plugin){
    LIBS+= -L$${SOURCE_DIR}/bin/$${PlatForm}/$${ARCHITECTURE}/$${DebugOrRelease}/Plugin -lCore -L$$DLLDESTDIR
    INCLUDEPATH+= $${SOURCE_DIR}/src/plugin/Core
    DEPENDPATH+=$${SOURCE_DIR}/src/plugin/Core
}

win32:{
    LIBS +=shell32.lib
    LIBS +=shlwapi.lib
    LIBS +=user32.lib
    LIBS +=comctl32.lib
    LIBS +=imm32.lib
}

#禁用qdebug打印输出
#DEFINES     += QT_NO_DEBUG_OUTPUT
