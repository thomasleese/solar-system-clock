cmake_minimum_required(VERSION 2.8.8)

project(sunset CXX)

include(ExternalProject)

ExternalProject_Add(
  sunset
  GIT_REPOSITORY https://github.com/buelowp/sunset.git
  PREFIX "${CMAKE_CURRENT_BINARY_DIR}"
)
