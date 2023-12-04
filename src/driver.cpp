/// @author [Jakob Germann, Software Engineer]
/// @date [2023]
/// @file driver
/// @brief Driver program that uses the implemented libraries and runs tests on their functionality

/// From C++ STL
#include <vector>
#include <cassert>

/// From libstructures
#include <linkedlist.h>
#include <stack.h>
#include <bitarray.h>

void testlibLinkedList(std::vector<uint8_t> &data)
{
    libdsa::libstructures::LinkedList<uint8_t> list;

    /// @test Confirm append() does append a new node to the end of the Linked List
    for (size_t i = 0; i < data.size(); ++i)
    {
        list.append(data[i]);
    }

    /// @test Confirm getHead() returns the first element of the Linked List.
    auto head = list.getHead();
    assert(head->_datum == 'C');

    /// @test Confirm the print() function works.
    list.print();

    /// @test Confirm the remove() function works for an index argument.
    size_t idx = 1;
    list.remove(idx);
    list.print();

    /// @test Confirm the insert function works as expected.
    list.insert('O', 1);
    list.print();

    /// @test Confirm the remove function works for a data instance argument.
    uint8_t item = 'O';
    list.remove(item);
    list.print();

    uint8_t item2 = '3';
    list.remove(item2);
    list.print();
}

void testlibStack(std::vector<uint8_t> &data)
{
    libdsa::libstructures::Stack<uint8_t> stack1(data.size());

    // Push individual elements
    for (size_t i = 0; i < data.size(); ++i)
    {
        stack1.push(data[i]);
    }

    // Confirm results
    while (!stack1.empty())
    {
        std::cout << stack1.pop();
    }

    std::cout << std::endl;
}

void testlibBitArray()
{
    libdsa::libstructures::BitArrayHandler handler();
}

int main()
{
    /// FIXME:  Need to fill the unused portion of the array up first. Seg faults otherwise.
    std::vector<uint8_t> data = {'C', 'O', 'D', 'E'};

    testlibLinkedList(data);
    testlibStack(data);

    testlibBitArray();
}