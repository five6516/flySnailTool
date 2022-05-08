cmake_minimum_required(VERSION 3.14)

set(Libs_PLUGIN_LIBRARY true)
add_definitions(-DLibs_PLUGIN_LIBRARY)

add_subdirectory(PluginManager)
add_subdirectory(UiManager)

