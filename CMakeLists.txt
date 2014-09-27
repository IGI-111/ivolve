CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(ivolve)

# Set Cmake to build runtime in cwd
SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

find_package(SFML 1.6 REQUIRED system window graphics network audio)

SET(CMAKE_CXX_FLAGS "-g -Wall -pthread -std=c++14")
ADD_SUBDIRECTORY(src)

