cmake_minimum_required(VERSION 3.19)
project(qor)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_MODULE_PATH "C:/dev/SDL2")

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})
add_executable(qor src/main.cpp src/RenderWindow.cpp src/RenderWindow.h src/Qor.cpp src/Qor.h src/Viewport.cpp src/Viewport.h src/Input.cpp src/Input.h src/Entity.cpp src/Entity.h src/Vect.h src/ai/btree/BTreeNode.h src/ai/btree/BTreeTask.h src/ai/Ai.cpp src/ai/Ai.h src/ai/btree/Behavior.cpp src/ai/btree/Behavior.h src/ai/btree/BTreeStatus.h src/ai/btree/BehaviorTrees.cpp src/ai/btree/BehaviorTrees.h src/ai/btree/tasks/MoveTo.cpp src/ai/btree/tasks/MoveTo.h src/ai/btree/tasks/DoNothing.cpp src/ai/btree/tasks/DoNothing.h src/Util.cpp src/Util.h src/Player.cpp src/Player.h src/ai/btree/Sequence.cpp src/ai/btree/Sequence.h src/ai/btree/checks/IsTargetAlive.h src/ai/btree/checks/IsTargetClose.h src/ai/btree/Selector.cpp src/ai/btree/Selector.h src/ai/btree/tasks/Fight.cpp src/ai/btree/tasks/Fight.h src/Logger.cpp src/Logger.h src/ai/btree/BTreeComposite.cpp src/ai/btree/BTreeComposite.h src/ai/btree/tasks/MoveCloseToTarget.cpp src/ai/btree/tasks/MoveCloseToTarget.h src/ai/btree/tasks/MoveToDestination.cpp src/ai/btree/tasks/MoveToDestination.h src/Mob.cpp src/Mob.h src/Item.cpp src/Item.h src/ai/btree/tasks/FindFood.cpp src/ai/btree/tasks/FindFood.h src/Target.cpp src/Target.h src/Destination.cpp src/Destination.h src/ai/btree/tasks/PickUpTarget.cpp src/ai/btree/tasks/PickUpTarget.h src/ai/btree/tasks/Eat.cpp src/ai/btree/tasks/Eat.h src/RenderShape.cpp src/RenderShape.h src/Map.cpp src/Map.h src/MapNode.cpp src/MapNode.h src/IBuilding.cpp src/IBuilding.h src/Body.cpp src/Body.h src/ai/btree/tasks/FindPositionToBuild.cpp src/ai/btree/tasks/FindPositionToBuild.h src/House.cpp src/House.h src/ai/btree/tasks/Build.cpp src/ai/btree/tasks/Build.h)
target_link_libraries(qor ${SDL2_LIBRARY})
