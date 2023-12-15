cmake_minimum_required(VERSION 3.20)
project(libdsa)

add_executable(${PROJECT_NAME} driver.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC "test/")
add_subdirectory(src)
