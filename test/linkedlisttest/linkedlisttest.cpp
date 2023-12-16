
// Source Class Header
#include <linkedlist.h>

// From C++ Standard Library
#include <memory>

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

/// @brief Google Test function that tests the append function when appending elements of a container.
TEST(LinkedList, testAppend)
{
    std::vector<uint8_t> data = {'C', 'O', 'D', 'E'};
    auto list = setup(data);

    libdsa::libstructures::Node<uint8_t>* head = list.getHead();

    for (size_t i = 0; i < list.getSize(); ++i)
    {
        ASSERT_EQ(head->_datum, data[i]);
        head = head->_next;
    }
}

