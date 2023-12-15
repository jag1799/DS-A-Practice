#include <bitarraytest.h>
#include <bitarray.h>

void libdsa::libstructures::BitArrayTests::testConstructorValidSize()
{
    std::vector<bool> s1 = {true, true, false};
    std::vector<bool> s2 = {false, false, true};

    const BitArrayHandler bitArr = BitArrayHandler(s1, s2);
}

