/// @author [Jakob Germann, Software Engineer]
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
                /// @return Result of ANDing the two vectors.
                std::vector<bool> AND();

                /// @brief Logical NOT of one of the two internal vectors.
                /// @param set1 Boolean to NOT either set1 or not (instead NOTing set2).
                /// @return A vector containing the result.
                std::vector<bool> NOT(bool set1);

                /// @brief Logical OR between both vectors and returns the new vectors.
                /// @return A vector containing the result of ORing the two vectors.
                std::vector<bool> OR();

                /// @brief Logical XOR between both vectors and returns the result.
                /// @return A vector containing the result of XORing the two vectors.
                std::vector<bool> XOR();

                /// @brief Set the contents of set 1.
                /// @param set The data to be used for set 1.
                void setSet1(std::vector<bool> &set);

                /// @brief Set the contents of set 2.
                /// @param set The data to be used for set 2.
                void setSet2(std::vector<bool> &set);

            private:
                std::vector<bool> _set1;
                std::vector<bool> _set2;
        };

        libdsa::libstructures::BitArrayHandler::BitArrayHandler(std::vector<bool> &set1, 
                                                                std::vector<bool> &set2) : 
                                                                _set1(set1), _set2(set2)
        {
            // Intentionally empty constructor
        }

        std::vector<bool> libdsa::libstructures::BitArrayHandler::AND()
        {
            std::vector<bool> result;
            
            if (_set1.size() != _set2.size())
            {
                std::cout << "Cannot compare Bit string of non-equal size." << std::endl;
            }
            else
            {
                for (size_t i = 0; i < _set1.size(); ++i)
                {
                    result.push_back(_set1[i] & _set2[i]);
                }
            }

            return result;
        }

        void libdsa::libstructures::BitArrayHandler::setSet1(std::vector<bool> &set) { _set1 = set; }

        void libdsa::libstructures::BitArrayHandler::setSet2(std::vector<bool> &set) { _set2 = set; }
    }
}


#endif

/// @}