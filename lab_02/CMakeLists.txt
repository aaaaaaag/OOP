cmake_minimum_required(VERSION 3.17)
project(lab_02_oop)

set(CMAKE_CXX_STANDARD 17)

add_library(${PROJECT_NAME} src/List.cpp inc/List.h)

target_include_directories(${PROJECT_NAME} PUBLIC include)


add_executable(${PROJECT_NAME}_debug main.cpp)

target_include_directories(${PROJECT_NAME}_debug PUBLIC include)
target_link_libraries(${PROJECT_NAME}_debug PRIVATE ${PROJECT_NAME})