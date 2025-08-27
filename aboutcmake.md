# 什么是CMake
CMake是一个构建系统，通过生成对应平台的构建文件(Makefile,Ninja)，再利用对应平台的构建文件来构建和编译程序。

# 使用流程
1. 编写CMakeLists.txt用于定义项目的构建规则、依赖关系、编译选项等
2. 生成构建文件，使用CMake来生成当前平台的构建文件(Makefile,Ninja,VS的工程文件)
3. 执行构建文件来编译项目