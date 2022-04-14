cmake_minimum_required(VERSION 3.14)

project(flySnailTool
    VERSION 1.0.0.0
    DESCRIPTION "flySnailTool"
    LANGUAGES CXX
)

# 根目录
set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

message("PROJECT_NAME = ${PROJECT_NAME}")
message("PROJECT_VERSION = ${PROJECT_VERSION}")
message("PROJECT_DESCRIPTION = ${PROJECT_DESCRIPTION}")

## Add paths to check for cmake modules:
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

add_subdirectory(src)
