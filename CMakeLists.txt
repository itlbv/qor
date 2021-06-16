cmake_minimum_required(VERSION 3.19)
project(qor)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})
add_executable(qor src/main.cpp src/RenderWindow.cpp src/RenderWindow.h src/Qor.cpp src/Qor.h src/Viewport.cpp src/Viewport.h src/Input.cpp src/Input.h src/Entity.cpp src/Entity.h src/Vect.h)
target_link_libraries(qor ${SDL2_LIBRARY})
