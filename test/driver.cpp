/// @author [Software Engineer]
/// @date [2023]
/// @file driver
/// @brief Driver program that uses the implemented libraries and runs tests on their functionality

// From gtest
#include <gtest/gtest.h>

int main(int argc, char **argv)
{
    std::cout << "Version: " << __cplusplus << std::endl;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}