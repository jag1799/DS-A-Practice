/// @author [Software Engineer]
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
    libdsa::structures::Stack<uint8_t> stack(data.size());

    ASSERT_EQ(data.size(), stack.getSize());
}

/// @brief Test if the push and pull functions work as expected given a specified set of values.
TEST(Stack, testPushPull)
{
    std::vector<uint8_t> data = {'C', 'O', 'D', 'E'};
    libdsa::structures::Stack<uint8_t> stack(data.size());

    for (size_t i = 0; i < data.size(); ++i)
    {
        ASSERT_NO_THROW(stack.push(data[i]));
    }

    for (short int i = data.size() - 1; i >= 0; --i)
    {
        ASSERT_EQ(data[i], stack.pop());
    }
}

/// @brief Test if the stack will pop when nothing is inside it.
TEST(Stack, testEmptyPop)
{
    libdsa::structures::Stack<uint8_t> stack(3);

    ASSERT_TRUE(stack.empty());

    ASSERT_EQ(0, stack.pop());

    libdsa::structures::Stack<std::string> stack2(5);

    ASSERT_TRUE(stack2.empty());

    ASSERT_EQ(0, stack.pop());
}

/// @brief Test if the stack will push when the maximum size is reached.
TEST(Stack, testPushWhenFull)
{
    std::vector<uint8_t> data{'K', 'N', 'K', 'F'};
    libdsa::structures::Stack<uint8_t> stack(3);

    for (size_t i = 0; i < data.size(); ++i)
    {
        stack.push(data[i]);
    }

    ASSERT_EQ('K', stack.pop());
}

/// @brief Test if the stack is actually empty upon creation.
TEST(Stack, testEmpty)
{
    libdsa::structures::Stack<uint8_t> stack(5);

    ASSERT_EQ(true, stack.empty());
}

/// @}