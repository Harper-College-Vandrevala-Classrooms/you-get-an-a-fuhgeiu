cmake_minimum_required(VERSION 3.28)
project(you_get_an_a_fuhgeiu)

set(CMAKE_CXX_STANDARD 14)

add_executable(you_get_an_a_fuhgeiu

        lab/execute/main.cpp
)


target_include_directories(lab/core data)

include_directories(lab/core data)
include_directories(lab/include)


