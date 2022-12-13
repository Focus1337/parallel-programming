cmake_minimum_required(VERSION 3.23)
project(ParallProg)

set(CMAKE_CXX_STANDARD 23)

# Add MPI Package to Project
find_package(MPI REQUIRED)

add_executable(ParallProg main.cpp Homeworks/Homeworks.h Seminars/Seminars.h Seminars/Seminar8.cpp Seminars/Seminar13.cpp Seminars/Seminar12.cpp Seminars/Seminar14.cpp)

# Add libraries for code completion and compiling
target_link_libraries(ParallProg PUBLIC MPI::MPI_CXX)