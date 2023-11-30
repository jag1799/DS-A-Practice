cmake_minimum_required(VERSION 3.20)
project(libdsa)

add_executable(${PROJECT_NAME} driver.cpp)
add_subdirectory(libstructures)