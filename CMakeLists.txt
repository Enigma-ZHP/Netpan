cmake_minimum_required(VERSION 3.10) # 最低版本
project(MyProject) # 项目名称

set(CMAKE_CXX_STANDARD 11) # 使用C++11版本

#include_directories(include) # 设置头文件目录

# 添加 lib 子目录
#add_subdirectory(lib)

# main 程序
#add_executable(netpan src/main.cpp src/foo.cpp src/bar.cpp)

# 链接 lib 子目录生成的库
#target_link_libraries(myprogram utils)

# 自动收集 src 目录下的所有 .cpp 文件
file(GLOB SOURCES "*.cpp")

# 生成可执行文件
add_executable(myprogram ${SOURCES})
