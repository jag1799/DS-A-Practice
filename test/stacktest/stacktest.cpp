/// @author [Jakob Germann, Software Engineer]
/// @date [2023]
/// @file stacktest
/// @brief Contains test functions for all member functions and use cases of the @c Stack class.
/// @{

// Class Header
#include <stack.h>

// From Gtest
#include <gtest/gtest.h>

/// @brief Test if the constructor builds the desired stack with the passed parameter.
TEST(Stack, testConstructor)
{
    std::vector<uint8_t> data = {'C', 'O', 'D', 'E'};
    libdsa::libstructures::Stack<uint8_t> stack(data.size());

    ASSERT_EQ(data.size(), stack.getSize());
}

/// @brief Test if the push and pull functions work as expected given a specified set of values.
TEST(Stack, testPushPull)
{
    std::vector<uint8_t> data = {'C', 'O', 'D', 'E'};
    libdsa::libstructures::Stack<uint8_t> stack(data.size());

    for (size_t i = 0; i < stack.getSize(); ++i)
    {
        ASSERT_NO_THROW(stack.push(data[i]));
    }

    for (size_t i = data.size() - 1; i >= 0; --i)
    {
        ASSERT_EQ(data[i], stack.pop());
    }
}

/// @brief Test if the stack will pop when nothing is inside it.

/// @brief Test if the stack will push when the maximum size is reached.

/// @brief Test if the stack is actually empty upon creation.
TEST(Stack, testEmpty)
{
    libdsa::libstructures::Stack<uint8_t> stack(5);

    ASSERT_EQ(true, stack.empty());
}

/// @}