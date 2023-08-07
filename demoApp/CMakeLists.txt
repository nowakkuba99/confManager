# ConfReader Demo Project by Jakub Nowak 2023

cmake_minimum_required(VERSION 3.13)  # CMake version check
project(confReader_Demo)               # Create project "confReader_Demo"
set(CMAKE_CXX_STANDARD 17)            # Enable c++17 standard

# Add main file
add_executable(${CMAKE_PROJECT_NAME} demoConfReader.cpp)

# ---- Link libraries ----
# AppToGIF
include_directories(${CMAKE_SOURCE_DIR}/../inc)
link_directories(${CMAKE_SOURCE_DIR}/../inc)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/../build/libconfReader.a)