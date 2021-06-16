cmake_minimum_required(VERSION 3.19)
project(qor)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})
add_executable(qor main.cpp)
target_link_libraries(qor ${SDL2_LIBRARY})
