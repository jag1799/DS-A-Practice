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

TEST(BitArray, testConstructorInvalidSize)
{
    std::vector<bool> s1{false, false, true};
    std::vector<bool> s2{true, false};

    ASSERT_THROW(libdsa::libstructures::BitArrayHandler bitArray(s1, s2), std::runtime_error);
}

TEST(BitArray, testAND_Operation)
{
    // Binary: 101
    std::vector<bool> s1{true, false, true};
    // Binary: 110
    std::vector<bool> s2{true, true, false};

    libdsa::libstructures::BitArrayHandler bitArray(s1, s2);

    // Expected Binary result: 100
    std::vector<bool> result = bitArray.AND();

    std::vector<bool> expected{true, false, false};

    ASSERT_EQ(expected, result);
}

TEST(BitArray, testOR_Operation)
{
    // Binary: 101
    std::vector<bool> s1{true, false, true};
    // Binary: 110
    std::vector<bool> s2{true, true, false};

    libdsa::libstructures::BitArrayHandler handler(s1, s2);

    // Expected Binary result: 111
    std::vector<bool> result = handler.OR();

    std::vector<bool> expected{true, true, true};

    ASSERT_EQ(expected, result);
}

TEST(BitArray, testXOR_Operation)
{
    // Binary: 101
    std::vector<bool> s1{true, false, true};
    // Binary: 110
    std::vector<bool> s2{true, true, false};

    libdsa::libstructures::BitArrayHandler handler(s1, s2);

    // Expected Binary Result: 011
    std::vector<bool> result = handler.XOR();

    std::vector<bool> expected{false, true, true};

    ASSERT_EQ(expected, result);
}

TEST(BitArray, testNOT_Operation)
{
    // Binary: 101
    std::vector<bool> s1{true, false, true};
    // Binary: 110
    std::vector<bool> s2{true, true, false};

    libdsa::libstructures::BitArrayHandler handler(s1, s2);

    // Expected Binary Result 1: 010
    handler.NOT(true);
    std::vector<bool> expected1 = {false, true, false};
    ASSERT_EQ(expected1, handler.getSet1());

    // Expected Binary Result 2: 001
    handler.NOT(false);
    std::vector<bool> expected2 = {false, false, true};
    ASSERT_EQ(expected2, handler.getSet2());
}