/// @author [Software Engineer]
/// @date [2023-2024]
/// @name ringbuffer
/// @{

#ifndef RINGBUFFER_H_
#define RINGBUFFER_H_

// From C++ STL
#include <iostream>
#include <utility>
#include <random>

namespace libdsa
{
    namespace libstructures
    {
        /// @brief Declaration and implementation of the @c RingBuffer class.  A ring buffer is a type of array
        ///        that loops back to the beginning index when the end index is reached during a write or read
        ///        operation.
        ///
        /// @tparam T Templated parameter that allows the ring buffer to be used with any data type.
        template <typename T>
        class RingBuffer
        {
        private:
            /// @brief Size of the ring buffer from start to the index for looping back to start.
            size_t _length;

            /// @brief The underlying Ring buffer storage.
            T *_buffer;

            /// @brief Index that is currently being written to.
            size_t _writeIndex;

            /// @brief Index that the user end can currently read from.
            size_t _readIndex;

        public:
            /// @brief Constructor
            RingBuffer(size_t length);

#ifdef TESTS
            size_t size();
#endif // TESTS

        }; // End RingBuffer

        template <typename T>
        libdsa::libstructures::RingBuffer<T>::RingBuffer(size_t length) : _length(length)
        {
            std::random_device device;
            std::mt19937 rng(device());
            std::uniform_int_distribution<std::mt19937::result_type> dist(0, _length - 1);

            this->_buffer = new T[this->_length];

            _writeIndex, _readIndex = dist(rng);
        }

#ifdef TESTS
        template <typename T>
        size_t libdsa::libstructures::RingBuffer<T>::size()
        {
            return _length;
        }
#endif // TESTS

    } // libstructures
} // libdsa

#endif // RINGBUFFER_H_

/// @}