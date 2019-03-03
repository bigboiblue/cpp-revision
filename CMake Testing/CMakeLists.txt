cmake_minimum_required(VERSION 2.8)
set(PROJECT_NAME "Test")
project(${PROJECT_NAME})
set(CMAKE_CXX_STANDARD 14 CACHE INTERNAL "") #C++14 std
set(CMAKE_CXX_FLAGS "-std=c++14 -Wall" CACHE INTERNAL "")
add_executable(${PROJECT_NAME} main.cpp Person.cpp)
if(${OOGABOOGA})
    message("\n============\nSUCK MY NUTS\n============\n")
endif()
