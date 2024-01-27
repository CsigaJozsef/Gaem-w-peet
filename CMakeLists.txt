cmake_minimum_required(VERSION 3.22) #CMake version check
project(csocs)

# set(CMAKE_CPP_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)
# set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

find_package(SDL2 REQUIRED)
include_directories(include/${SDL2_INCLUDE_DIRS})

file(GLOB SOURCES "src/*.cpp")
add_executable(csocs ${SOURCES})
target_link_libraries(csocs ${SDL2_LIBRARIES})

# cmake -D CMAKE_CXX_COMPILER=g++ ../