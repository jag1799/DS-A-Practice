/// @author [Software Engineer]
/// @date [2024]
/// @file ringbuffertest
/// @brief Contains test functions for all member functions and use cases
///        of the @c RingBuffer class.

// Class Header
#include <ringbuffer.h>

// From Gtest
#include <gtest/gtest.h>

std::vector<uint8_t> data = {'C', 'O', 'D', 'E'};

/// @brief Test the constructor builds a valid buffer to the expected size.
TEST(RingBuffer, testConstructor)
{
    libdsa::libstructures::RingBuffer<uint8_t> ringBuffer(data.size());

    ASSERT_EQ(ringBuffer.size(), data.size());
}

/// @brief Test we can make valid writes and reads to and from a buffer that's not full.
TEST(RingBuffer, testWriteReadValidDataBelowFullBuffer)
{
    libdsa::libstructures::RingBuffer<uint8_t> ringBuffer(data.size());

    ASSERT_EQ(ringBuffer.size(), data.size());

    for (size_t i = 0; i < data.size() - 1; ++i)
    {
        ringBuffer.write(data[i]);
    }

    for (size_t i = 0; i < ringBuffer.size(); ++i)
    {
        switch (i)
        {
        case 0:
            ASSERT_EQ('C', ringBuffer.read());
            break;
        case 1:
            ASSERT_EQ('O', ringBuffer.read());
            break;
        case 2:
            ASSERT_EQ('D', ringBuffer.read());
            break;
        default:
            break;
        };
    }
}

TEST(RingBuffer, testWriteReadValidDataFullBuffer)
{
    libdsa::libstructures::RingBuffer<uint8_t> ringBuffer(data.size());
    ASSERT_EQ(ringBuffer.size(), data.size());

    for (size_t i = 0; i < data.size(); ++i)
    {
        ringBuffer.write(data[i]);
    }

    // Iterate through each index of the ring buffer that we write to.  Should be the entire size of the buffer regardless
    // of starting index.
    for (size_t i = 0; i < ringBuffer.size(); ++i)
    {
        switch (i)
        {
        case 0:
            ASSERT_EQ('C', ringBuffer.read());
            break;
        case 1:
            ASSERT_EQ('O', ringBuffer.read());
            break;
        case 2:
            ASSERT_EQ('D', ringBuffer.read());
            break;
        case 3:
            ASSERT_EQ('E', ringBuffer.read());
            break;
        default:
            break;
        };
    }
}

TEST(RingBuffer, testWriteInvalidType)
{
    libdsa::libstructures::RingBuffer<uint8_t> ringBuffer(data.size());
    ASSERT_EQ(ringBuffer.size(), data.size());

    int instance = 4;
    ASSERT_THROW(ringBuffer.write(instance), std::runtime_error);
}

TEST(RingBuffer, testOverwriteExistingData)
{
    libdsa::libstructures::RingBuffer<uint8_t> ringBuffer(data.size());
    ASSERT_EQ(ringBuffer.size(), data.size());

    for (size_t i = 0; i < data.size(); ++i)
    {
        ringBuffer.write(data[i]);
        ringBuffer.read();
    }

    uint8_t datum = 'A';
    ringBuffer.write(datum);

    ASSERT_EQ('A', ringBuffer.read());
}

TEST(RingBuffer, testAttemptedReadPastWriteIndex)
{
    libdsa::libstructures::RingBuffer<uint8_t> ringBuffer(data.size());
    ASSERT_EQ(ringBuffer.size(), data.size());

    for (size_t i = 0; i < data.size(); ++i)
    {
        ringBuffer.write(data[i]);
    }

    ASSERT_EQ('C', ringBuffer.read());
    ASSERT_EQ('O', ringBuffer.read());
    ASSERT_EQ('D', ringBuffer.read());
    ASSERT_EQ('E', ringBuffer.read());

    // Read the same value as the write index.
    ASSERT_EQ('C', ringBuffer.read());

    // Read past the write index regardless of what it says.
    ASSERT_EQ('O', ringBuffer.read());
}