cmake_minimum_required(VERSION 3.0)
project(Imager)

# ccache
find_program(CCACHE_FOUND ccache)
set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/home/lavandejoey/Qt/5.15.14/gcc_64/lib/cmake/")
find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        Multimedia
        MultimediaWidgets
        REQUIRED)
message(STATUS "Found Qt ${Qt5_VERSION}\n"
        "    Qt5_DIR ${Qt5_DIR}"
)

# spdlog
find_package(spdlog REQUIRED)
if (spdlog_FOUND)
    message(STATUS "Found spdlog ${spdlog_VERSION}:\n"
            "    spdlog_DIR ${spdlog_DIR}")
else ()
    set(SPDLOG_INCLUDE_DIR "3rdparty/include/spdlog")
    include_directories(${SPDLOG_INCLUDE_DIR})
    #3rdparty/lib/libspdlog.a
    link_libraries(${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/lib/libspdlog.a)
    find_package(spdlog REQUIRED)
    message(STATUS "Found spdlog ${spdlog_VERSION}:\n"
            "    spdlog_DIR ${spdlog_DIR}")
endif ()

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_BINARY_DIR}
)
add_executable(Imager ImagerMain.cpp
        imager.cpp
        imager.h
        imager.ui
        settings.cpp
        settings.h
        settings.ui
        settings.cpp
        settings.h
        settings.ui
        about.cpp
        about.h
        about.ui
        config.cpp
        config.h
)
target_link_libraries(Imager
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Multimedia
        Qt5::MultimediaWidgets
)
