cmake_minimum_required(VERSION 3.21)
project(untitled)
set(CMAKE_CXX_STANDARD 14)

add_executable(untitled glad.c main.cpp)
set(GLAD_DIR "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(${PROJECT_NAME} GL dl glfw)