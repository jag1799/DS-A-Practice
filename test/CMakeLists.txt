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

add_executable(libdsa_test 
                    driver.cpp
                    bitarraytest/bitarraytest.cpp
                    linkedlisttest/linkedlisttest.cpp
                    stacktest/stacktest.cpp)

target_link_libraries(libdsa_test
    PRIVATE
    GTest::GTest
    libdsa)

add_test(libdsa_gtests libdsa_test)