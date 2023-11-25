cmake_minimum_required(VERSION 3.20)
project(DSA)


add_executable(${PROJECT_NAME} driver.cpp)
add_subdirectory(libstructures)

# target_link_directories(${PROJECT_NAME} PUBLIC "libstructures/")