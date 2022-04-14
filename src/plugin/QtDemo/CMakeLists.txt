cmake_minimum_required(VERSION 3.14)

project(QtDemo
    VERSION 1.0.0
    DESCRIPTION "QtDemo plugin"
    LANGUAGES CXX
)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets)

# 包含 plugin cmake
include(plugin)

# 包含编译设置
include(global_compile)

file(GLOB DIR_HEADERS *.h)
file(GLOB DIR_UI *.ui)
aux_source_directory(. DIR_SRCS)

add_library(QtDemo SHARED
  ${DIR_SRCS}
  ${VERSIONINFO_RC}
  ${MACRO_H}
  ${DIR_HEADERS}
  ${DIR_UI}
)

target_link_libraries(QtDemo Qt${QT_VERSION_MAJOR}::Core
                             Qt${QT_VERSION_MAJOR}::Widgets
                             UiManager
                             Core)
