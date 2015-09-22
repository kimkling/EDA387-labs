cmake_minimum_required(VERSION 3.3)
project(Lab3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES server-iterative.cpp client-multi.cpp client-simple.cpp)
add_executable(Lab3 ${SOURCE_FILES})