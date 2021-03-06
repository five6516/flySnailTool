cmake_minimum_required(VERSION 3.14)

project(Core
    VERSION 1.0.0
    DESCRIPTION "core plugin"
    LANGUAGES CXX
)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets)

# 包含 plugin cmake
include(plugin)

# 包含编译设置
include(global_compile)

file(GLOB DIR_UI ui/*.*)

aux_source_directory(. DIR_SRCS)

add_library(Core SHARED
  ${DIR_SRCS}
  ${VERSIONINFO_RC}
  ${MACRO_H}
  ${DIR_UI}
)

target_include_directories(Core PUBLIC ${ROOT_DIR}/src/libs/UiManager
                                       ${ROOT_DIR}/src/libs/PluginManager)

target_link_libraries(Core Qt${QT_VERSION_MAJOR}::Core
                           Qt${QT_VERSION_MAJOR}::Widgets
                           UiManager
                           PluginManager)

target_include_directories(Core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/PluginManager
                                       ${CMAKE_CURRENT_SOURCE_DIR}/Application)

#add_subdirectory(PluginManager)
add_subdirectory(Application)
