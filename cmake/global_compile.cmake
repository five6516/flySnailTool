# Global Compile

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# 平台区分
if(UNIX)
    set(PlatForm Unix)
    set(CMAKE_CXX_FLAGS -fvisibility=hidden)
    set(CMAKE_EXE_LINKER_FLAGS -Wl,-rpath=.,-no-pie)
elseif(WIN32)
    set(PlatForm Windows)
    set(CMAKE_CXX_FLAGS /MP)
elseif(ANDROID)
    set(PlatForm Android)
elseif(APPLE)
    set(PlatForm apple)
else()
    set(PlatForm None)
endif()

# Debug Release区分
if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")

elseif(${CMAKE_BUILD_TYPE} STREQUAL "Release")

endif()

# x64 x32区分
if(CMAKE_CL_64)
    set(ARCHITECTURE x64)
else()
    set(ARCHITECTURE x86)
endif()

# 输出根目录
set(OUT_DIR ${ROOT_DIR}/bin/${PlatForm}/${ARCHITECTURE}/${CMAKE_BUILD_TYPE})

if (DEFINED FlySnail_PLUGIN_LIBRARY)#插件
  set(LIBRARY_OUTPUT_PATH ${OUT_DIR}/Plugin)
elseif(DEFINED Libs_PLUGIN_LIBRARY)#库
  set(LIBRARY_OUTPUT_PATH ${OUT_DIR})
else()
  set(EXECUTABLE_OUTPUT_PATH ${OUT_DIR})
  set(LIBRARY_OUTPUT_PATH ${OUT_DIR})
endif ()

# 版本号
if(WIN32)
    set(VERSIONINFO_RC "${CMAKE_CURRENT_SOURCE_DIR}/VersionInfo.rc")
    configure_file("${ROOT_DIR}/cmake/VersionInfo.rc.in"
                   "${VERSIONINFO_RC}")
endif()


# 宏定义配置
set(MACRO_H "${CMAKE_CURRENT_SOURCE_DIR}/Macro.h")
configure_file("${ROOT_DIR}/cmake/Macro.h.in"
               ${MACRO_H})
