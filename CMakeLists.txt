cmake_minimum_required(VERSION 3.2)

project(SolarSystemClock)

find_package(PkgConfig REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z -Wall -pedantic")

include_directories(include)

add_subdirectory(lib)
add_subdirectory(src)
