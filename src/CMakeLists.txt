cmake_minimum_required(VERSION 3.14)

# 源码目录
set(SRC_DIR ${ROOT_DIR}/src)
# 设置 插件路径
set(LIBS_DIR ${ROOT_DIR}/src/libs)
# 设置 插件路径
set(PLUGIN_DIR ${ROOT_DIR}/src/plugin)

add_subdirectory(libs)
add_subdirectory(main)
add_subdirectory(plugin)
