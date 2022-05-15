cmake_minimum_required(VERSION 3.14)

project(Main
    VERSION 1.0.1
    DESCRIPTION "flySnailTool"
    LANGUAGES CXX
)

set(FlySnail_EXE true)
add_definitions(-DFlySnail_EXE)

# 包含编译设置
include(global_compile)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)

set(TS_FILES flySnailGui_en_US.ts)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(flySnailGui
        MANUAL_FINALIZATION
        main.cpp
        ${TS_FILES}
        ${VERSIONINFO_RC}
    )
else()
    add_executable(flySnailGui
        main.cpp
        ${TS_FILES}
        ${VERSIONINFO_RC}
    )
endif()

target_link_libraries(flySnailGui PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

if(COMMAND qt_create_translation)
    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

set_target_properties(flySnailGui PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)


if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(flySnailGui)
endif()















