include_directories(${ROOT_DIR}/src/plugin)
include_directories(${ROOT_DIR}/src/plugin/Global)

#定义插件库宏
set(FlySnail_PLUGIN_LIBRARY true)
add_definitions(-DFlySnail_PLUGIN_LIBRARY)
