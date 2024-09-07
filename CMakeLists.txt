cmake_minimum_required(VERSION 3.16)
project(LibDSA LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

# Logger settings.  INFO and ERROR are always enabled by default.
set(DEBUG "DEBUG")
set(WARNING "WARNING")
set(CRITICAL "CRITICAL")

add_compile_definitions(TESTS ON)
set(LOG_LEVEL DEBUG)

# Print everything to assist in debugging operations.
if ("${LOG_LEVEL}" STREQUAL "DEBUG")
    add_compile_definitions(DEBUG ON)
endif()

if ("${LOG_LEVEL}" STREQUAL "WARNING" OR 
    "${LOG_LEVEL}" STREQUAL "DEBUG" OR 
    "${LOG_LEVEL}" STREQUAL "CRITICAL")
    add_compile_definitions(WARNING ON)
endif()

if ("${LOG_LEVEL}" STREQUAL "CRITICAL" OR 
    "${LOG_LEVEL}" STREQUAL "DEBUG")
    add_compile_definitions(CRITICAL ON)
endif()

add_subdirectory(test)
add_subdirectory(src)
