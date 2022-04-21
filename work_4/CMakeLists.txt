cmake_minimum_required(VERSION 3.20)
project(hw_4)

set(CMAKE_CXX_STANDARD 23)

add_executable(regex regex.cpp)
add_executable(json task_1/json_main.cpp json_main.hpp task_1/json.h task_1/filesystem_json.h)