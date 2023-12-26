/// @author [Software Engineer]
/// @date [2023]
/// @file bitarraytest
/// @brief Contains test functions for all member functions and use cases of @c BitArray.

// Source Class Header
#include <bitarray.h>

// From Gtest
#include <gtest/gtest.h>

TEST(BitArray, testConstructorValidSize)
{
    std::vector<bool> s1{false, false, true, true};
    std::vector<bool> s2{true, false, true, true};

    libdsa::libstructures::BitArrayHandler bitArray = libdsa::libstructures::BitArrayHandler(s1, s2);
    ASSERT_EQ(s1, bitArray.getSet1());
    ASSERT_EQ(s2, bitArray.getSet2());
}