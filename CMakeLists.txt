#                       Jakub Nowak 2023
#                  https://github.com/nowakkuba99

# This CMake project allows one to create static library confReader

# CMake Version
cmake_minimum_required(VERSION 3.13)
# Project Name
project(confReader)
# C++17 Standard
set(CMAKE_CXX_STANDARD 17)
# Source files paths
set(SOURCE_FILES 
    src/test.cpp
    )
# Add library
add_library(${CMAKE_PROJECT_NAME} STATIC ${SOURCE_FILES})
# Add includes
include_directories(${CMAKE_SOURCE_DIR}/inc)
link_directories(${CMAKE_SOURCE_DIR}/inc)
# --------------------------------------------------------------
# ----------------------- DEPENDENCIES -------------------------
# --------------------------------------------------------------
# To be also used in your project ...