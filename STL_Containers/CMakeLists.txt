#cmake
cmake_minimum_required(VERSION 3.5)
project(stl_container)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(vector_list_deque Vector_List_Deque.cpp)
add_executable(maps maps.cpp)
add_executable(sets sets.cpp)
add_executable(Stack Stack.cpp)
add_executable(Queue Queue.cpp)