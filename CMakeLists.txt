cmake_minimum_required(VERSION 3.5)

project(demo02 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(SOURCES
    "src/main.cpp"
    "src/MainWindow.cpp"
)

set(HEADERS
    "src/MainWindow.h"
)

add_executable(demo02 
    ${SOURCES}
    ${HEADERS}
)


target_link_libraries(demo02 PRIVATE Qt5::Widgets)
