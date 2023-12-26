/// @author [Software Engineer]
/// @date [2023-2024]
/// @name bitarray
/// @brief Contains declaration and definition of a Bit array wrapper using the @c std::vector<bool> method.
/// @{

#ifndef BITARRAY_H_
#define BITARRAY_H_

/// @details A bit array is a space-optimized container for storing individual bits. Due to processor architecture
/// being built to work with bytes specifically, operating on individual bits takes additional processing time and can
/// vary between hardware systems.  One of the better C++ methods of implementing this data structure is to use the
/// @c std::vector<bool> construct which triggers additional space optimization, if able.

#include <vector>
#include <iostream>
#include <stdexcept>
#include <string>

namespace libdsa
{
    namespace libstructures
    {
        /// @brief Handles and performs operations on two user defined bit arrays.
        class BitArrayHandler
        {
        public:
            /// @brief Default constructor
            BitArrayHandler() = default;

            /// @brief Constructor
            /// @param set1 First Bit array.
            /// @param set2 Second Bit array.
            BitArrayHandler(std::vector<bool> &set1, std::vector<bool> &set2);

            /// @brief Logical AND between both vectors and returns the new vectors.
            /// @return A vector containing the intersection of the two vectors.
            std::vector<bool> AND();

            /// @brief Logical difference between the two vectors
            /// @note Operation: difference[i] = set1[i] AND (NOT set2[i])
            /// @return A vector containing the difference of the two internal sets.
            // std::vector<bool> difference();

            std::vector<bool> getSet1();

            std::vector<bool> getSet2();

            /// @brief Logical NOT of one of the two internal vectors.
            /// @param set1 Boolean to NOT either set1 or not (instead NOTing set2).
            /// @return A vector containing complement of the chosen vector.
            void NOT(bool set1);

            /// @brief Logical OR between both vectors and returns the new vectors.
            /// @return A vector containing the result of ORing the two vectors.
            std::vector<bool> OR();

            /// @brief Set the contents of set 1.
            /// @param set The data to be used for set 1.
            void setSet1(std::vector<bool> &set);

            /// @brief Set the contents of set 2.
            /// @param set The data to be used for set 2.
            void setSet2(std::vector<bool> &set);

            /// @brief Logical XOR between both vectors and returns the result.
            /// @return A vector containing the result of XORing the two vectors.
            std::vector<bool> XOR();

        private:
            std::vector<bool> _set1;
            std::vector<bool> _set2;

            size_t _size;
        };

        libdsa::libstructures::BitArrayHandler::BitArrayHandler(std::vector<bool> &set1,
                                                                std::vector<bool> &set2) : _set1(set1), _set2(set2)
        {
            if (_set1.size() != _set2.size())
            {
                throw std::runtime_error("Vectors must be the same size");
            }
            else
            {
                _size = _set1.size();
            }
        }

        std::vector<bool> libdsa::libstructures::BitArrayHandler::AND()
        {
            std::vector<bool> result;

            for (size_t i = 0; i < _size; ++i)
            {
                result.push_back(_set1[i] & _set2[i]);
            }

            return result;
        }

        std::vector<bool> libdsa::libstructures::BitArrayHandler::getSet1()
        {
            return _set1;
        }

        std::vector<bool> libdsa::libstructures::BitArrayHandler::getSet2()
        {
            return _set2;
        }

        void libdsa::libstructures::BitArrayHandler::NOT(bool set1)
        {
            for (size_t i = 0; i < _size; ++i)
            {
                if (set1)
                {
                    _set1[i] = ~_set1[i];
                }
                else
                {
                    _set2[i] = ~_set2[i];
                }
            }
        }

        std::vector<bool> libdsa::libstructures::BitArrayHandler::OR()
        {
            std::vector<bool> result;

            for (size_t i = 0; i < _size; ++i)
            {
                result.push_back(_set1[i] | _set2[i]);
            }

            return result;
        }

        void libdsa::libstructures::BitArrayHandler::setSet1(std::vector<bool> &set)
        {
            if (set.size() == _size)
            {
                _set1 = set;
            }
            else
            {
                std::cout << "Incompatible Bitstream size." << std::endl;
            }
        }

        void libdsa::libstructures::BitArrayHandler::setSet2(std::vector<bool> &set)
        {
            if (set.size() == _size)
            {
                _set2 = set;
            }
            else
            {
                std::cout << "Incompatible Bitstream size." << std::endl;
            }
        }

        std::vector<bool> libdsa::libstructures::BitArrayHandler::XOR()
        {
            std::vector<bool> result;

            for (size_t i = 0; i < _size; ++i)
            {
                result.push_back(_set1[i] ^ _set2[i]);
            }

            return result;
        }
    }
}

#endif

/// @}