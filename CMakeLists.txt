cmake_minimum_required(VERSION 3.2)

project(SolarSystemClock)

add_subdirectory(cmake/sdl)
add_subdirectory(cmake/spdlog)
add_subdirectory(cmake/sunset)

add_subdirectory(lib)
add_subdirectory(src)
