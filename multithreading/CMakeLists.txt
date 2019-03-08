cmake_minimum_required(VERSION 3.00)
project(multithreading)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall" CACHE INTERNAL "")
#To make a var in CMakeCache.txt from commmand line use -D flag with cmake:
#e.g. cmake .. -DBUILD_TESTING:BOOL=ON

add_executable(multithreading main.cpp)

# Using and including <thread> from std library on unix may require you to link pthread library (POSIX thread)
# Windows Handles this differently
if(UNIX)
    find_library(P_THREAD pthread HINTS /lib/)
    target_link_directories(multithreading PRIVATE ${P_THREAD})
    #PRIVATE means program used lib in implementation (most are private)
    #INTERFACE means B is not used in implementation, but definitions are manipulated
    #PUBLIC is a mix of both

    #This is not a non-standard library, so I do not need to specify link directory by using find_library then target_link_directories (just doing it for tutorial)
    target_link_libraries(multithreading pthread)
endif()