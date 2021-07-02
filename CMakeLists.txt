cmake_minimum_required(VERSION 3.19)
project(qor)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})
add_executable(qor src/main.cpp src/RenderWindow.cpp src/RenderWindow.h src/Qor.cpp src/Qor.h src/Viewport.cpp src/Viewport.h src/Input.cpp src/Input.h src/Entity.cpp src/Entity.h src/Vect.h src/ai/btree/Node.h src/ai/btree/Task.cpp src/ai/btree/Task.h src/ai/Ai.cpp src/ai/Ai.h src/ai/btree/Behavior.cpp src/ai/btree/Behavior.h src/ai/btree/Status.h src/ai/btree/BehaviorTrees.cpp src/ai/btree/BehaviorTrees.h src/ai/btree/tasks/MoveTo.cpp src/ai/btree/tasks/MoveTo.h src/ai/btree/tasks/DoNothing.cpp src/ai/btree/tasks/DoNothing.h src/Util.cpp src/Util.h src/Player.cpp src/Player.h src/ai/btree/Composite.cpp src/ai/btree/Composite.h src/ai/btree/Sequence.cpp src/ai/btree/Sequence.h src/ai/btree/checks/IsTargetAlive.h src/ai/btree/checks/IsTargetClose.h src/ai/btree/Selector.cpp src/ai/btree/Selector.h)
target_link_libraries(qor ${SDL2_LIBRARY})
