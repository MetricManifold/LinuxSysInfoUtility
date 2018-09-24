cmake_minimum_required(VERSION 2.6)
project(3307IndividualAssignment)

set(CPP_STANDARD_FLAGS "-std=c++17")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CPP_STANDARD_FLAGS}")

file(GLOB SOURCES "*.cpp")
add_executable(3307IndividualAssignment ${SOURCES})

