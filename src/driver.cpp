
// From C++ STL
#include <array>
#include <functional>

#include <linkedlist.h>

int main()
{
    /// FIXME:  Need to fill the unused portion of the array up first. Seg faults otherwise.
    std::array<uint8_t, 10> data = {'C', 'O', 'D', 'E'};
    data.fill(0x00);
    data = {'C', 'O', 'D', 'E'};

    for (size_t i = 0; i < data.size(); ++i)
    {
        std::printf("%c", data[i]);
    }
    std::printf("\n");

    libdsa::libstructures::LinkedList<uint8_t> list;

    for (size_t i = 0; i < data.size(); ++i)
    {
        list.append(data[i]);
    }

    list.print();
}