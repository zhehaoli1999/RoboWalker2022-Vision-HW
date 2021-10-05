cmake_minimum_required(VERSION 3.16) # cmake要求的最低版本
project(RoboWalker-Vision2022_HW)  # project的名字

# 设置C++标准
set(CMAKE_CXX_STANDARD 20)

# 找到OpenCV lib与需要include的头文件的路径，并输出相关信息
find_package(OpenCV  REQUIRED)
message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

# 指出需要头文件所在的路径，#include<xx.h>的时候需要根据这个路径来查找
include_directories(${OpenCV_INCLUDE_DIRS})

# 输出项目源文件所在的目录
message(STATUS "Project source dir: ${PROJECT_SOURCE_DIR}/")

# 下面两条指令用于将二进制文件输出到指定目录
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# 将生成的二进制文件放在源文件所在的目录
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}) 

# 查找后缀为.cpp的源文件，并打印出来找到的内容
FILE(GLOB_RECURSE SOURCE "Detector/*.cpp" "Preprocessor/*.cpp" "Utils/*.cpp")
message(STATUS "Source files: ${SOURCE}")

# 指出连接时查找lib的路径
link_directories("/usr/local/lib/")

# 增加可执行文件（.cpp文件）
add_executable(${PROJECT_NAME} main.cpp ${SOURCE})

# 将Opencv的链接库链接到Project
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
