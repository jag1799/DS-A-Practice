# AUTHOR: Jakob Germann
# LAST EDIT DATE: 12/25/2023

include(FetchContent)

option(BUILD_GMOCK OFF)
option(INSTALL_GTEST OFF)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.11.0
)

FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(libdsa_structures_test
                    driver.cpp
                    structures/binarytreetest/binarytreetest.cpp
                    structures/bitarraytest/bitarraytest.cpp
                    structures/linkedlisttest/linkedlisttest.cpp
                    structures/ringbuffertest/ringbuffertest.cpp
                    structures/stacktest/stacktest.cpp)

target_link_libraries(libdsa_structures_test
    PRIVATE
    GTest::GTest
    libdsa)

add_test(libdsa_structures_gtest libdsa_structures_test)