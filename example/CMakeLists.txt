# 基本配置
cmake_minimum_required(VERSION 2.0)
project(intrin_helper_example CXX)

# 头文件位置
include_directories(../)

# 编译选项
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "-O3 -fopenmp -ftree-vectorize -Wall")

# 添加源文件目录到SRC变量
# set(SRC1 src/arrayadd.cpp)

# 生成可执行文件
add_executable(../bin/verify_instr_checker src/verify_instr_checker.cpp)