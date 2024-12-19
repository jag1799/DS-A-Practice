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
    namespace structures
    {
        /// @brief Declaration and implementation of the @c RingBuffer class.  A ring buffer is a type of array
        ///        that loops back to the beginning index when the end index is reached during a write or read
        ///        operation.
        ///
        /// @note The RNG for the selection of the index requires C++17 or greater.
        ///
        /// @tparam T Templated parameter that allows the ring buffer to be used with any data type.
        template <typename T>
        class RingBuffer
        {
        private:
            /// @brief The underlying Ring buffer storage.
            T *_buffer;

            /// @brief Check the type of the data being written into the buffer, which has type K
            /// @tparam K The type of the data being passed into the buffer.  This must match the
            ///           the type of the ring buffer, T.  Otherwise a runtime error will be thrown.
            /// @param data The actual data being written to the buffer.
            template <typename K>
            void checkType(K data);

            /// @brief Size of the ring buffer from start to the index for looping back to start.
            size_t _length;

            /// @brief Index that is currently being written to.
            uint16_t _writeIndex;

            /// @brief Index that the user end can currently read from.
            uint16_t _readIndex;

        public:
            /// @brief Constructor
            /// @param length The size of the ring buffer.  This will not change as ring buffers
            ///               are typically fixed in size by nature.
            RingBuffer(size_t length);

            /// @brief Read the value at the index of readIndex and move to the next index.
            /// @return The data at the current readIndex.
            T read();

            /// @brief Write to the ring buffer at the current writeIndex value. The index will
            ///        loop back to index 0 when the end of the buffer is reached and overwrite
            ///        anything that may have been there, including the index where the readIndex
            ///        currently is.
            /// @tparam K The type of the data being passed into the buffer.  This must match the
            ///           specified type of the Ring Buffer, T.  Otherwise, the program will throw
            ///           a runtime failure and crash.
            /// @param data The variable containing the data to be stored by the ring buffer.
            template <typename K>
            void write(K data);

#ifdef TESTS
            /// @brief Test function to verify that the read index has reached the expected index.
            /// @return The index that we're ready to read to.
            uint16_t getReadIndex();

            /// @brief Test function to verify that the write index has reached the expected index.
            /// @return The index that we're ready to write to.
            uint16_t getWriteIndex();

            /// @brief Test function to verify the constructor builds the buffer at the
            ///        designated size.
            /// @return The size of the ring buffer.
            size_t size();
#endif // TESTS

        }; // End RingBuffer

        template <typename T>
        libdsa::structures::RingBuffer<T>::RingBuffer(size_t length) : _length(length)
        {
            std::random_device device;
            std::mt19937 rng(device());
            std::uniform_int_distribution<std::mt19937::result_type> dist(0, this->_length - 1);

            this->_buffer = new T[this->_length];

            this->_writeIndex = dist(rng);
            this->_readIndex = this->_writeIndex;
        }

        template <typename T>
        template <typename K>
        void libdsa::structures::RingBuffer<T>::checkType(K data)
        {
            if constexpr (!std::is_same_v<T, K>)
            {
                throw std::runtime_error("Invalid type being written to RingBuffer.");
            }
        }

        template <typename T>
        T libdsa::structures::RingBuffer<T>::read()
        {
            // If we reach the end index of the buffer, loop back to the beginning.
            if (this->_readIndex == this->_length - 1)
            {
                uint16_t oldRead = this->_readIndex;
                this->_readIndex = 0;
                return this->_buffer[oldRead];
            }
            // Simply read the current data.
            else
            {
                return this->_buffer[this->_readIndex++];
            }
        }

        template <typename T>
        template <typename K>
        void libdsa::structures::RingBuffer<T>::write(K data)
        {
            checkType(data);
            // If we reach the end of the buffer, write to the final index and loop back to the beginning.
            if (this->_writeIndex == this->_length - 1)
            {
                this->_buffer[this->_writeIndex] = data;
                this->_writeIndex = 0;
            }
            // Write the data, even if we overlap the readIndex value.  We can overwrite whatever is stored here.
            else
            {
                this->_buffer[this->_writeIndex] = data;
                ++this->_writeIndex;
            }
        }

#ifdef TESTS
        template <typename T>
        uint16_t libdsa::structures::RingBuffer<T>::getReadIndex()
        {
            return this->_readIndex;
        }

        template <typename T>
        uint16_t libdsa::structures::RingBuffer<T>::getWriteIndex()
        {
            return this->_writeIndex;
        }

        template <typename T>
        size_t libdsa::structures::RingBuffer<T>::size()
        {
            return this->_length;
        }
#endif // TESTS

    } // structures
} // libdsa

#endif // RINGBUFFER_H_

/// @}