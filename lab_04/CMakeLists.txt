cmake_minimum_required(VERSION 3.0)
project(lab_04)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)

add_library(${PROJECT_NAME} inc/cabin.hpp inc/control_panel.hpp inc/doors.hpp inc/lift.hpp inc/direction.hpp
        src/cabin.cpp src/control_panel.cpp src/doors.cpp src/lift.cpp)


add_executable(${PROJECT_NAME}_debug
        main.cpp
        inc/mainwindow.h
        src/mainwindow.cpp
        )

target_include_directories(${PROJECT_NAME}_debug PRIVATE
        ./inc
        ./src
        )

target_include_directories(${PROJECT_NAME} PRIVATE
        ./inc
        ./src
        )


find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
target_link_libraries(${PROJECT_NAME}_debug ${REQUIRED_LIBS_QUALIFIED} ${PROJECT_NAME})