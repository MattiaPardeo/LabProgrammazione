cmake_minimum_required(VERSION 3.23)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES eseguiTest.cpp)
add_executable(TestFoglio ${TEST_SOURCE_FILES})
target_link_libraries(TestFoglio gtest gtest_main core)