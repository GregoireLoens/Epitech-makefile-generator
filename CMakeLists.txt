cmake_minimum_required(VERSION 3.6)
project(Epitech_makefile_generator)

set(CMAKE_CXX_STANDARD 11)

include_directories(includes)

set(SOURCE_FILES
        includes/MakefileClass.hpp
        sources/main.cpp
        sources/MakefileClass.cpp
        )

add_executable(Epitech_makefile_generator ${SOURCE_FILES})