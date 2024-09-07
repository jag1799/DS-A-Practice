/// @author [Software Engineer]
/// @date [2023]
/// @file linkedlisttest
/// @brief Contains test functions for all member functions and use cases of the @c LinkedList class.

// Class Header
#include <linkedlist.h>

// From Gtest
#include <gtest/gtest.h>

// From C++ STL
#include <random>

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

    for (size_t i = 0; i < data.size(); ++i)
    {
        list.append(data[i]);
    }

    libdsa::libstructures::Node<uint8_t> *head = list.getHead();

    ASSERT_EQ(data.size(), list.getSize());

    for (size_t i = 0; i < list.getSize(); ++i)
    {
        ASSERT_EQ(head->_datum, data[i]);
        head = head->_next;
    }
}

/// @brief Test that the container class will handle an invalid append attempt.
TEST(LinkedList, testInvalidAppend)
{
    std::vector<uint8_t> data = {'C', 'O', 'D', 'E'};
    libdsa::libstructures::LinkedList<uint8_t> list = setup(data);

    float temp = 23.22;
    bool temp2 = false;
    double temp3 = 42.2e3;

    ASSERT_THROW(list.append(temp), std::runtime_error);
    ASSERT_THROW(list.append(temp2), std::runtime_error);
    ASSERT_THROW(list.append(temp3), std::runtime_error);
}

/// @brief Test that the overloaded '[]' operator returns the correct data for the index.
TEST(LinkedList, testValidIndexRetrieval)
{
    std::vector<uint8_t> data = {'C', 'O', 'D', 'E'};
    libdsa::libstructures::LinkedList<uint8_t> list = setup(data);

    ASSERT_EQ('C', list[0]);
    ASSERT_EQ('O', list[1]);
    ASSERT_EQ('D', list[2]);
    ASSERT_EQ('E', list[3]);
}

/// @brief Test that the container class handles an out of bounds error appropriately.
TEST(LinkedList, testOutOfBoundsIndexRetrieval)
{
    std::vector<uint8_t> data = {'C', 'O', 'D', 'E'};
    libdsa::libstructures::LinkedList<uint8_t> list = setup(data);

    ASSERT_THROW(list[4], std::runtime_error);
}

/// @brief Test that the container class removes the correct data instance given an index.
TEST(LinkedList, testValidRemoveByIndex)
{
    std::vector<uint8_t> data = {'C', 'O', 'D', 'E'};
    libdsa::libstructures::LinkedList<uint8_t> list = setup(data);

    size_t idx = 2;
    list.removeByIndex(idx);

    ASSERT_EQ('E', list[2]);
}

/// @brief Test that the container class correctly handles an invalid removal given a bad index value.
TEST(LinkedList, testInvalidRemoveByIndex)
{
    std::vector<uint8_t> data = {'C', 'O', 'D', 'E'};
    libdsa::libstructures::LinkedList<uint8_t> list = setup(data);

    size_t idx = 5;
    ASSERT_THROW(list.removeByIndex(idx), std::runtime_error);
}

/// @brief Test that the container class removes a data instance given said instance.
TEST(LinkedList, testValidRemoveByData)
{
    std::vector<uint8_t> data = {'C', 'O', 'D', 'E'};
    libdsa::libstructures::LinkedList<uint8_t> list = setup(data);

    uint8_t datum = 'O';

    list.removeByData(datum);

    ASSERT_EQ('D', list[1]);
}

/// @brief Test that the container class does not remove data given an non-existing data instance.
/// @note Also ensure that the program does not terminate upon the removal attempt.
TEST(LinkedList, testInvalidRemoveByData)
{
    std::vector<uint8_t> data = {'C', 'O', 'D', 'E'};
    libdsa::libstructures::LinkedList<uint8_t> list = setup(data);

    uint8_t datum = 'K';

    list.removeByData(datum);

    ASSERT_EQ('O', list[1]);
}

/// @brief Test that the container will insert the requested data into the correct index.
TEST(LinkedList, testValidInsert)
{
    std::vector<uint8_t> data = {'C', 'O', 'D', 'E'};
    libdsa::libstructures::LinkedList<uint8_t> list = setup(data);

    uint8_t datum = '4';

    list.insert(datum, 1);

    ASSERT_EQ('4', list[1]);
}

/// @brief Test that the container class will not insert data into an invalid position (out of bounds).
TEST(LinkedList, testInvalidInsert)
{
    std::vector<uint8_t> data = {'C', 'O', 'D', 'E'};
    libdsa::libstructures::LinkedList<uint8_t> list = setup(data);

    uint8_t datum = '5';
    ASSERT_THROW(list.insert(datum, 6), std::runtime_error);
}

/// @brief Test that the container will not insert an incompatible data type into the container.
TEST(LinkedList, testInvalidTypeInsert)
{
    std::vector<uint8_t> data = {'C', 'O', 'D', 'E'};
    libdsa::libstructures::LinkedList<uint8_t> list = setup(data);

    int datum = 32;

    ASSERT_THROW(list.insert(datum, 3), std::runtime_error);
}

TEST(LinkedList, testFindInvalidType)
{
    std::vector<uint8_t> data = {'C', 'O', 'D', 'E'};
    libdsa::libstructures::LinkedList<uint8_t> list = setup(data);

    int datum = 32;

    ASSERT_THROW(list.exists(datum), std::runtime_error);
}

TEST(LinkedList, testFindValidTypeMiddle)
{
    std::vector<uint8_t> data = {'C', 'O', 'D', 'E'};
    libdsa::libstructures::LinkedList<uint8_t> list = setup(data);

    uint8_t datum = 'D';

    ASSERT_TRUE(list.exists(datum));
}

TEST(LinkedList, testFindValidTypeStart)
{
    std::vector<uint8_t> data = {'C', 'O', 'D', 'E'};
    libdsa::libstructures::LinkedList<uint8_t> list = setup(data);

    uint8_t datum = 'C';

    ASSERT_TRUE(list.exists(datum));
}

TEST(LinkedList, testFindValidTypeEnd)
{
    std::vector<uint8_t> data = {'C', 'O', 'D', 'E'};
    libdsa::libstructures::LinkedList<uint8_t> list = setup(data);

    uint8_t datum = 'E';

    ASSERT_TRUE(list.exists(datum));
}

TEST(LinkedList, testFindValidTypeFailure)
{
    std::vector<uint8_t> data = {'C', 'O', 'D', 'E'};
    libdsa::libstructures::LinkedList<uint8_t> list = setup(data);

    uint8_t datum = 'K';

    ASSERT_FALSE(list.exists(datum));
}

TEST(LinkedList, testFindValidTypeSuccessWithLargeList)
{
    libdsa::libstructures::LinkedList<int> list;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1, 100);
    int number = 0;
    for (size_t i = 0; i < 10000; ++i)
    {
        number = distribution(generator);
        list.append(number);
    }

    ASSERT_EQ(10000, list.getSize());

    list.insert(110, 8000);

    ASSERT_EQ(10001, list.getSize());

    ASSERT_TRUE(list.exists(110));
}