# 使用CMake Tools插件（可选，如果这个项目去到一个没有这个插件的机器也同样可以生成项目）
# include(CMakeToolsHelpers OPTIONAL)
set(CMAKE_GENERATOR "MinGW Makefiles")
# CMake 最低版本号要求
cmake_minimum_required(VERSION 3.12)
# 项目名称
project(projectName VERSION 0.0.1)
message("构建？？" ${CMAKE_GENERATOR})
# 设置编译选项（debug or release）
IF (NOT CMAKE_BUILD_TYPE)
    SET(CMAKE_BUILD_TYPE "Release")
ENDIF ()

# 打印工程编译选项
MESSAGE("BUILD TYPE(构建类型):" ${CMAKE_BUILD_TYPE})
# 设置编译器（C/C++）
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")
# 设置使用 mingw makefile
set(CMAKE_GENERATOR "MinGW Makefiles")
set(PROJECT_BINARY_DIR ${PROJECT_SOURCE_DIR}/build)

# 预设变量
#PROJECT_SOURCE_DIR # 工程的根目录
#PROJECT_BINARY_DIR # 运行 cmake 命令的目录，通常是 ${PROJECT_SOURCE_DIR}/build
#PROJECT_NAME # 返回通过 project 命令定义的项目名称
#CMAKE_CURRENT_SOURCE_DIR # 当前处理的 CMakeLists.txt 所在的路径
#CMAKE_CURRENT_BINARY_DIR # target 编译目录
#CMAKE_CURRENT_LIST_DIR # CMakeLists.txt 的完整路径
#CMAKE_CURRENT_LIST_LINE # 当前所在的行
#CMAKE_MODULE_PATH # 定义自己的 cmake 模块所在的路径，SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)，然后可以用INCLUDE命令来调用自己的模块
#EXECUTABLE_OUTPUT_PATH # 重新定义目标二进制可执行文件的存放位置
#LIBRARY_OUTPUT_PATH # 重新定义目标链接库文件的存放位置
#CMAKE_SOURCE_DIR # 工程目录
#CMAKE_BINARY_DIR # 一般是build目录
# // 设置文件路径

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_ROOT_SRCS变量
aux_source_directory(. DIR_ROOT_SRCS)

# 添加 Lib子目录
add_subdirectory(./lib)
#设置编译文件以及输出路径
set(EXECUTABLE_OUTPUT_PATH ./bin)
# 指定生成目标
add_executable(main main.cpp)
add_executable(ex1 ex1.cpp)
add_executable(ex2 ex2.cpp)

# 添加链接库
# target_link_libraries(programName PrinterLib)

MESSAGE("PROJECT_BINARY_DIR:--在哪里---" ${PROJECT_BINARY_DIR} "\n")