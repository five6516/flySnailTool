cmake_minimum_required(VERSION 3.14)

# 设置 插件路径
set(LIBS_DIR ${ROOT_DIR}/src/libs)

set(Libs_PLUGIN_LIBRARY true)
add_definitions(-DLibs_PLUGIN_LIBRARY)

add_subdirectory(UiManager)
