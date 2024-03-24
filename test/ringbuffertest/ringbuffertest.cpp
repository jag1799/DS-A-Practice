/// @author [Software Engineer]
/// @date [2024]
/// @file ringbuffertest
/// @brief Contains test functions for all member functions and use cases
///        of the @c RingBuffer class.

// Class Header
#include <ringbuffer.h>

// From Gtest
#include <gtest/gtest.h>

TEST(RingBuffer, testConstructor)
{
    std::vector<uint8_t> data = {'C', 'O', 'D', 'E'};
    libdsa::libstructures::RingBuffer<uint8_t> ringBuffer(data.size());

    ASSERT_TRUE(ringBuffer.size() <= data.size());
}