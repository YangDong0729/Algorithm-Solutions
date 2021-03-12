# CMakeList.txt: Algorithm-Solutions 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.17)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 11)

project("Algorithm Solutions")

add_subdirectory("PAT")
add_subdirectory("浙大版《数据结构（第2版）》题目集/编程题")
add_subdirectory("浙大版《数据结构学习与实验指导（第2版）》题目集/编程题")