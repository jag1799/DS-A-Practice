/// @author [Jakob Germann, Software Engineer]
/// @date [2023]
/// @file linkedlisttest
/// @brief Contains test functions for all member functions and use cases of @c LinkedList.

// Source Class Header
#include <linkedlist.h>

// From Gtest
#include <gtest/gtest.h>

/// @brief Reusable setup function for a LinkedList tests.
/// @param data Container of data to build the linked list with.
/// @return A fully built Linked List instance containing data.
libdsa::libstructures::LinkedList<uint8_t> setup(std::vector<uint8_t> &data)
{
    libdsa::libstructures::LinkedList<uint8_t> list;

    for (size_t i = 0; i < data.size(); ++i)
    {
        list.append(data[i]);
    }
    
    return list;
}

/// @test Google Test function that tests the append function when appending elements of a container.
TEST(LinkedList, testValidAppend)
{
    std::vector<uint8_t> data = {'C', 'O', 'D', 'E'};

    libdsa::libstructures::LinkedList<uint8_t> list;

    // TEST: Append the data and verify below.
    for (size_t i = 0; i < data.size(); ++i)
    {
        list.append(data[i]);
    }

    libdsa::libstructures::Node<uint8_t>* head = list.getHead();
    
    ASSERT_EQ(data.size(), list.getSize());

    for (size_t i = 0; i < list.getSize(); ++i)
    {
        ASSERT_EQ(head->_datum, data[i]);
        head = head->_next;
    }
}

/// @test that attempting to insert a value of a different type does nothing to the list. 
TEST(LinkedList, testInvalidAppend)
{
    std::vector<uint8_t> data = {'C', 'O', 'D', 'E'};
    auto list = setup(data);

    float temp = 23.22;
    bool temp2 = false;
    double temp3 = 42.2e3;

    ASSERT_THROW(list.append(temp), std::runtime_error);
    ASSERT_THROW(list.append(temp2), std::runtime_error);
    ASSERT_THROW(list.append(temp3), std::runtime_error);
}

TEST(LinkedList, testRemoveByIdx)
{
    std::vector<uint8_t> data = {'C', 'O', 'D', 'E'};
    auto list = setup(data);

    size_t idx = 2;
    list.removeByIndex(idx);

    // ASSERT_EQ('E', list[2]);
}