/// @author [Software Engineer]
/// @date [2023-2024]
/// @name ringbuffer
/// @{

#ifndef RINGBUFFER_H_
#define RINGBUFFER_H_

namespace libdsa
{
    namespace libstructures
    {
        template <typename T>
        class RingBuffer
        {
        private:
            /// @brief Size of the ring buffer from start to the index for looping back to start.
            size_t length;

            /// @brief The underlying Ring buffer storage.
            T start[length];

            /// @brief Index that is currently being written to.
            size_t writeIndex;

            /// @brief Index that the user end can currently read from.
            size_t readIndex;
        };
    }
}
#endif

/// @}