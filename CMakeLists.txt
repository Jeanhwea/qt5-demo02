cmake_minimum_required(VERSION 3.10)

project(demo02
    VERSION 0.0.0
    DESCRIPTION "Qt GUI Application"
    LANGUAGES CXX)


set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Qt 自动生成设置
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# C++ 标准设置
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找 Qt 依赖
find_package(Qt5 COMPONENTS Widgets REQUIRED)

# 头文件
set(HEADERS
    "include/ui/MainWindow.h"
    "include/ui.h")

# 源文件
set(SOURCES
    "src/main.cpp"
    "src/ui/MainWindow.cpp")

# 添加可执行文件
add_executable(demo02
    ${SOURCES}
    ${HEADERS})

# 链接库
target_link_libraries(demo02 PRIVATE Qt5::Widgets)
