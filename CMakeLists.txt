cmake_minimum_required(VERSION 3.10)

project(demo02
  VERSION 0.0.4
  DESCRIPTION "Qt GUI Application"
  LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Qt 自动生成设置
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 确保所有源文件使用 UTF-8 编码编译
if(MSVC)
    # 对 Visual Studio 编译器设置 UTF-8 编码
    add_compile_options(/utf-8)
else()
    # 对其他编译器设置 UTF-8 编码
    add_compile_options(-finput-charset=UTF-8 -fexec-charset=UTF-8)
endif()

# 查找 Qt 依赖
find_package(Qt5 COMPONENTS Widgets REQUIRED)

# 头文件
set(HEADERS
  "include/components.h"
  "include/logger.h"
  "include/ui/MainWindow.h"
  "include/ui/jx/JxHBoxLayout.h"
  "include/ui/jx/JxPushButton.h"
  "include/ui/jx/JxVBoxLayout.h"
  "include/ui/jx/JxWidget.h"
  "include/util.h"
)

# 源文件
set(SOURCES
  "source/logger.cpp"
  "source/main.cpp"
  "source/ui/MainWindow.cpp"
  "source/ui/jx/JxHBoxLayout.cpp"
  "source/ui/jx/JxPushButton.cpp"
  "source/ui/jx/JxVBoxLayout.cpp"
  "source/ui/jx/JxWidget.cpp"
  "source/util.cpp"
)

# 添加可执行文件
add_executable(demo02
    ${SOURCES}
    ${HEADERS})

if(WIN32)
  set_target_properties(demo02 PROPERTIES
    WIN32_EXECUTABLE $<IF:$<CONFIG:Release>,ON,OFF>
  )
endif()

# 链接库
target_link_libraries(demo02 PRIVATE Qt5::Widgets)
