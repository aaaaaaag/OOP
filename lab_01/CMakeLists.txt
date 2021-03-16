cmake_minimum_required(VERSION 3.17)
project(lab_01_oop)

set(CMAKE_CXX_STANDARD 17)

add_library(${PROJECT_NAME} include/DotStruct.h include/DotFileIO.h src/DotFileIO.cpp
        include/Errors.h include/DotStructUtils.h src/DotStructUtils.cpp
        src/Qt/MainMenu.cpp include/Qt/MainMenu.h src/Qt/MoveButton.cpp include/Qt/MoveButton.h
        src/Qt/ZoomButton.cpp include/Qt/ZoomButton.h src/Qt/RotateButton.cpp include/Qt/RotateButton.h
        src/Qt/LoadFileButton.cpp include/Qt/LoadFileButton.h include/Logic.h src/Logic.cpp src/Qt/ActionSlots.cpp include/Qt/ActionSlots.h src/Qt/MoveShapeUI.cpp include/Qt/MoveShapeUI.h src/Qt/RotateShapeUI.cpp include/Qt/RotateShapeUI.h src/Qt/ZoomShapeUI.cpp include/Qt/ZoomShapeUI.h include/FillGraphicWidget.h src/FillGraphicWidget.cpp src/DotStruct.cpp include/Qt/CanvasStruct.h src/Qt/CanvasStruct.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS} -std=c++1y")
find_package(Qt5Widgets REQUIRED)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)

target_include_directories(${PROJECT_NAME} PUBLIC include)


add_executable(${PROJECT_NAME}_debug main.cpp)

target_include_directories(${PROJECT_NAME}_debug PUBLIC include)
target_link_libraries(${PROJECT_NAME}_debug PRIVATE ${PROJECT_NAME})