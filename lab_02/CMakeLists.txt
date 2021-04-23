cmake_minimum_required(VERSION 3.17)
project(lab_02_oop)

set(CMAKE_CXX_STANDARD 17)

add_library(${PROJECT_NAME} inc/ConstListIterator.h
        inc/List.h
        inc/ListIterator.h
        inc/ListNode.h
        inc/SkeletonContainer.h
        inc/fake.cpp
        inc/ConstListIterator.hpp
        inc/List.hpp
        inc/ListIterator.hpp
        inc/ListNode.hpp)

target_include_directories(${PROJECT_NAME} PRIVATE inc)

add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)


add_executable(${PROJECT_NAME}_debug main.cpp)
target_include_directories(${PROJECT_NAME}_debug PRIVATE inc)
target_link_libraries(${PROJECT_NAME}_debug PUBLIC ${PROJECT_NAME})

add_executable(${PROJECT_NAME}_tests tests/TestListNode.cpp tests/TestListInterator.cpp)
target_include_directories(${PROJECT_NAME}_tests PRIVATE inc)
target_link_libraries(${PROJECT_NAME}_tests PUBLIC ${PROJECT_NAME} gtest gtest_main)
#target_link_libraries(${PROJECT_NAME}_tests gtest gtest_main)