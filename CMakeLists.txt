cmake_minimum_required(VERSION 3.23)
project(LabProgrammazione)

set(CMAKE_CXX_STANDARD 14)

find_package(wxWidgets REQUIRED net gl core base xrc adv)
include(${wxWidgets_USE_FILE})

add_executable(LabProgrammazione main.cpp)

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})