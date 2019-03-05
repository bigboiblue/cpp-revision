cmake_minimum_required(VERSION 3.13)
project(multithreading)

set(CMAKE_CXX_STANDARD 14)

add_executable(multithreading main.cpp)

# Using and including <thread> from std library on unix may require you to link pthread library (POSIX thread)
# Windows Handles this differently
if(UNIX)
    target_link_libraries(multithreading pthread)
endif()
