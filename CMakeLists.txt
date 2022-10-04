cmake_minimum_required(VERSION 3.23)
project(ParallProg)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")


add_executable(ParallProg main.cpp Seminar3.cpp HW2.cpp HW1.cpp Homework1.cpp Homework1.h)
