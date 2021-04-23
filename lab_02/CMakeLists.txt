cmake_minimum_required(VERSION 3.17)
project(lab_02_oop)

set(CMAKE_CXX_STANDARD 17)

set(PROJECT_HEADERS
        inc/ConstListIterator.h
        inc/List.h
        inc/ListIterator.h
        inc/ListNode.h
        inc/SkeletonContainer.h
        )
set(PROJECT_SOURCES
        main.cpp
        inc/ConstListIterator.hpp
        inc/List.hpp
        inc/ListIterator.hpp
        inc/ListNode.hpp
        tests/TestListNode.cpp)

add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)



add_executable(${PROJECT_NAME}_debug ${PROJECT_SOURCES} ${PROJECT_HEADERS})
target_link_libraries(${PROJECT_NAME}_debug gtest gtest_main)
#target_include_directories(${PROJECT_NAME}_debug PUBLIC inc)
#target_link_libraries(${PROJECT_NAME}_debug PRIVATE ${PROJECT_NAME})