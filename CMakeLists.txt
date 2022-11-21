cmake_minimum_required(VERSION 3.21)

# C++ settings
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS OFF)

# Project configuration
project(student-tasks-review CXX)

# add task directories below
add_subdirectory(prints-words-by-predicates)
add_subdirectory(cocktail-shaker-sort)
add_subdirectory(linked-lists)
