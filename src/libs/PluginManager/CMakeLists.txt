cmake_minimum_required(VERSION 3.14)

project(PluginManager
    VERSION 1.0.0
    DESCRIPTION "PluginManager lib"
    LANGUAGES CXX
)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets)

# 包含编译设置
include(global_compile)

add_library(${PROJECT_NAME} STATIC
    LibraryPathSet.cpp
    LibraryPathSet.h
    PluginManage.cpp
    PluginManage.h
    PluginSpec.cpp
    PluginSpec.h)

target_include_directories(${PROJECT_NAME} PUBLIC ${PLUGIN_DIR})

target_link_libraries(${PROJECT_NAME} Qt${QT_VERSION_MAJOR}::Core
                                     Qt${QT_VERSION_MAJOR}::Widgets)
