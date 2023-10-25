#include <array>
#include <iostream>
#include "LinkedList.h"

int main()
{
    std::array<uint8_t, 10> data = {'C', 'O', 'D', 'E'};

    for (size_t i = 0; i < data.size(); ++i)
    {
        std::printf("%c", data[i]);
    }
    std::printf("\n");
}