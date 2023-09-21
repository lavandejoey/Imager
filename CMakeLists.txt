cmake_minimum_required(VERSION 3.26)
project(Imager)

# ccache
find_program(CCACHE_FOUND ccache)
set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/home/lavandejoey/Qt/5.15.14/gcc_64/lib/cmake")
find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        Multimedia
        MultimediaWidgets
        REQUIRED)


add_executable(Imager ImagerMain.cpp
        Configs.cpp
        Configs.h)
target_link_libraries(Imager
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Multimedia
        Qt5::MultimediaWidgets
)

