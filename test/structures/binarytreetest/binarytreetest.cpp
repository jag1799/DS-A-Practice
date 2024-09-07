/// @author [jag1799]
/// @date [2024]
/// @file binarytreetest
/// @brief Contains test functions for all member functions and use cases of the @c BinaryTree class.
/// @{

// Class Header
#include <binarytree.h>

// From Gtest
#include <gtest/gtest.h>

/// @brief Tests the basic constructor  
TEST(BinaryTree, test_emptyConstructor)
{
    ASSERT_NO_THROW(auto tree = libdsa::structures::tree::BinaryTree<uint8_t>());
}

TEST(BinaryTree, test_validArrayConstructor)
{
    std::array<uint8_t, 5> array = {'C', 'O', 'D', 'E'};

    ASSERT_NO_THROW(auto tree = libdsa::structures::tree::BinaryTree<uint8_t>(array));
}

TEST(BinaryTree, test_invalidArrayConstructor)
{
    std::array<int, 5> array = {1, 2, 3, 4};

    ASSERT_THROW(auto tree = libdsa::structures::tree::BinaryTree<uint8_t>(array), std::runtime_error);
}

TEST(BinaryTree, test_validVectorConstructor)
{
    std::vector<uint8_t> vector = {'C', 'O', 'D', 'E'};

    ASSERT_NO_THROW(auto tree = libdsa::structures::tree::BinaryTree<uint8_t>(vector));
}

TEST(BinaryTree, test_invalidVectorConstructor)
{
    std::vector<int> vector = {1, 2, 3, 4};
    ASSERT_THROW(auto tree = libdsa::structures::tree::BinaryTree<uint8_t>(vector), std::runtime_error);
}

TEST(BinaryTree, test_validSizeRequestWithEmptyTree)
{
    auto tree = libdsa::structures::tree::BinaryTree<uint8_t>();
    ASSERT_EQ(0, tree.Size());
}