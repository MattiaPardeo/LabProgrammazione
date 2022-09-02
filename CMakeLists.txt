cmake_minimum_required(VERSION 3.23)
project(LabProgrammazione)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(test)

find_package(wxWidgets REQUIRED net gl core base xrc adv)
include(${wxWidgets_USE_FILE})

set(SOURCE_FILES  Observer.h Subject.h FinestraView.cpp FinestraView.h Controller.cpp Controller.h TabellaModel.cpp TabellaModel.h)

add_executable(LabProgrammazione main.cpp)

add_library(core ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES} core)