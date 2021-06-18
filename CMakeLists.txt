cmake_minimum_required(VERSION 3.19)
project(qor)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})
add_executable(qor src/main.cpp src/RenderWindow.cpp src/RenderWindow.h src/Qor.cpp src/Qor.h src/Viewport.cpp src/Viewport.h src/Input.cpp src/Input.h src/Entity.cpp src/Entity.h src/Vect.h src/ai/btree/Node.h src/ai/btree/BehaviorTree.cpp src/ai/btree/BehaviorTree.h src/ai/btree/Task.cpp src/ai/btree/Task.h src/ai/Ai.cpp src/ai/Ai.h src/ai/btree/Root.cpp src/ai/btree/Root.h src/ai/btree/Behavior.cpp src/ai/btree/Behavior.h src/ai/btree/Status.h)
target_link_libraries(qor ${SDL2_LIBRARY})
