#cmake
cmake_minimum_required(VERSION 3.5)
project(stl_iterator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(iterators iterators.cpp)
add_executable(sorting sorting.cpp)
add_executable(count_accumulate count_accumulate.cpp)
add_executable(transform_algorithms transform_algorithms.cpp)
add_executable(find_if_algo find_if_algo.cpp)
add_executable(utility_classes utility_classes.cpp)