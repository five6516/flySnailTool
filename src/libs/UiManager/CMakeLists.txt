cmake_minimum_required(VERSION 3.14)

project(UiManager
    VERSION 1.0.0
    DESCRIPTION "UiManager lib"
    LANGUAGES CXX
)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets)

# 包含编译设置
include(global_compile)

file(GLOB DIR_HEADERS *.h)
file(GLOB DIR_HEADERS form/*.h)
aux_source_directory(. DIR_SRCS)
aux_source_directory(form DIR_SRCS)

set(HEADERS ${DIR_HEADERS}
                utils/UiHelper.h)
set(SOURCES ${DIR_SRCS}
                utils/UiHelper.cpp)


add_library(UiManager SHARED
  ${HEADERS}
  ${SOURCES}
  ${VERSIONINFO_RC}
  ${MACRO_H}
)

target_link_libraries(UiManager Qt${QT_VERSION_MAJOR}::Core
                                     Qt${QT_VERSION_MAJOR}::Widgets)

