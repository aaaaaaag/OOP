cmake_minimum_required(VERSION 3.17)
project(clion_oop_3)

set(CMAKE_CXX_STANDARD 17)

file(GLOB srcFiles commands/* exceptions/* facade/* intermediary/* math/* objects/* render/* scene/*
        transformations/* uploading/* visitor/* BaseManager.h DrawLabel.h DrawLabel.cpp MainWindow.h MainWindow.cpp)


add_library(${PROJECT_NAME} ${srcFiles})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS} -std=c++1y")
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Charts REQUIRED)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Charts)

add_executable(${PROJECT_NAME}_debug main.cpp)
target_link_libraries(${PROJECT_NAME}_debug PUBLIC ${PROJECT_NAME})