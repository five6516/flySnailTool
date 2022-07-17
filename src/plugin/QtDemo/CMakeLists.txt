cmake_minimum_required(VERSION 3.14)

project(QtDemo
    VERSION 1.0.0
    DESCRIPTION "QtDemo plugin"
    LANGUAGES CXX
)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets Concurrent)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets Concurrent)

# 包含 plugin cmake
include(plugin)

# 包含编译设置
include(global_compile)

file(GLOB DIR_FILES
    *.*
    BuildIn/*.*
    Thread/*.*
)

include_directories(
    BuildIn
    Thread
)

add_library(QtDemo SHARED
  ${DIR_FILES}
  ${VERSIONINFO_RC}
  ${MACRO_H}
)

target_link_libraries(QtDemo Qt${QT_VERSION_MAJOR}::Core
                             Qt${QT_VERSION_MAJOR}::Widgets
                             Qt${QT_VERSION_MAJOR}::Concurrent
                             UiManager
                             Core)
