/// @author [Jakob Germann, Software Engineer]
/// @date [2023-2024]
/// @name bitarraytest
/// @brief Contains test declarations for the @c BitArray class.
/// @{

#ifndef BITARRAYTEST_H_
#define BITARRAYTEST_H_

namespace libdsa
{
    namespace libstructures
    {
        namespace BitArrayTests
        {
            void testDefaultConstructor();
            void testConstructorValidSize();
            void testConstructorInvalidSize();
            void testSetContainer1();
            void testSetContainer2();
            void testAndOp();
            void testOrOp();
            void testNegationOp();
            void testXorOp();
        }
    }
}

#endif

/// @}