cmake_minimum_required(VERSION 3.16) # cmake要求的最低版本
project(RoboWalker-Vision2022_HW_1)  # project的名字

# 设置C++标准
set(CMAKE_CXX_STANDARD 20)

# 查找后缀为.cpp的源文件，并打印出来找到的内容
# FILE(GLOB_RECURSE SOURCE "src/*.cpp" )
# message(STATUS "Source files: ${SOURCE}")

# 增加可执行文件（.cpp文件）
add_executable(${PROJECT_NAME} src/main.cpp src/MyVec.cpp)