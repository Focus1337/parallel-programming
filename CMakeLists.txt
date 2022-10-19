cmake_minimum_required(VERSION 3.23)
project(ParallProg)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")


add_executable(ParallProg main.cpp Seminars/Seminar3.cpp Homeworks/Homework1.cpp Homeworks/Homeworks.h Seminars/Seminars.h Homeworks/Homework2.cpp Seminars/Seminar4.cpp Seminars/Seminar5.cpp Homeworks/Homework3.cpp Seminars/Seminar6.cpp)
