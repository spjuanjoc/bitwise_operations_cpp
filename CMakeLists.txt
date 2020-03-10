cmake_minimum_required(VERSION 3.15)
project(bitwise_operations_cpp)

set(CMAKE_CXX_STANDARD 17)

# For googletest
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread ")

set(SOURCES
        main.cpp
        # other.cpp
        )

# To get the headers
#include_directories(Module)
#include_directories(Test/Module)

add_executable(${PROJECT_NAME} ${SOURCES})