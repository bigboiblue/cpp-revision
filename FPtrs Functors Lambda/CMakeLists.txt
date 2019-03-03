cmake_minimum_required(VERSION 3.13)
project(FPtrs_Functors_Lambda)

set(CMAKE_CXX_STANDARD 14 CACHE INTERNAL "" FORCE)
set(CMAKE_CXX_FLAGS "-std=c++14 -Wall" CACHE INTERNAL "" FORCE)

add_executable(FPtrs_Functors_Lambda main.cpp maths.cpp maths.h)