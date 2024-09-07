/// @author [Software Engineer]
/// @date [2024]
/// @file tree
/// @{

#ifndef TREE_H_
#define TREE_H_

// From C++ STL
#include <array>
#include <random>
#include <type_traits>
#include <vector>

// From libutilities
#include <node.h>

namespace libdsa
{
    namespace structures
    {
        namespace tree
        {
            template <typename Type>
            class BinaryTree
            {

                public:

                    /// @brief Constructor for an empty Binary Tree.
                    BinaryTree();

                    /// @brief Constructor from an std::array container.
                    ///
                    /// @tparam Subtype The data type of the array.
                    /// @tparam SIZE The size of the array
                    ///
                    /// @param container The container we want to build from defined by the template parameters.
                    template <typename Subtype, std::size_t SIZE>
                    BinaryTree(std::array<Subtype, SIZE> &container);

                    /// @brief Constructor from an std::vector container.
                    ///
                    /// @tparam Subtype The internal data type of the vector.
                    ///
                    /// @param container The container we want to build from defined by the template parameters.
                    template <typename Subtype>
                    BinaryTree(std::vector<Subtype> &container);

                    /// @brief Getter to get the number of nodes within the tree.
                    ///
                    /// @return The number of nodes within the Binary Tree.
                    size_t Size();
                
                private:

                    /// @brief Checks that the type of the tree and the data instance are the same.
                    ///
                    /// @tparam Subtype The type of the datum instance.
                    ///
                    /// @param datum The actual datum we're comparing to the Tree type.
                    template <typename Subtype>
                    void _checkTypeCompatability(Subtype);

                    /// @brief Top most node in the Binary Tree.
                    libdsa::libstructures::TreeNode<Type> *_head;

                    /// @brief Number of nodes within the Binary Tree.
                    size_t _size;
            }; // BinaryTree

            template <typename Type>
            libdsa::structures::tree::BinaryTree<Type>::BinaryTree() : _size(0)
            {
                // Intentionally empty constructor
            }

            template <typename Type>
            template <typename Subtype, std::size_t SIZE>
            libdsa::structures::tree::BinaryTree<Type>::BinaryTree(std::array<Subtype, SIZE> &container) : _size(0)
            {
                // Get the type of elements and verify they're the same as the type of the Binary Tree
                using array_element_type = typename std::remove_reference<decltype(*std::begin(container))>::type;
                array_element_type temp;
                _checkTypeCompatability(temp);

                for (size_t i = 0; i < container.size(); ++i)
                {
                    if (i == 0)
                    {
                        this->_head = new libdsa::libstructures::TreeNode<Type>(container[i]);
                    }
                    else
                    {
                        // Add a child in a random side
                    }
                }
            }

            template <typename Type>
            template <typename Subtype>
            libdsa::structures::tree::BinaryTree<Type>::BinaryTree(std::vector<Subtype> &container) : _size(0)
            {
                using vector_element_type = typename std::remove_reference<decltype(*std::begin(container))>::type;
                vector_element_type temp;
                _checkTypeCompatability(temp);

                for (size_t i = 0; i < container.size(); ++i)
                {
                    if (i == 0)
                    {
                        this->_head = new libdsa::libstructures::TreeNode<Type>(container[i]);
                    }
                }
            }

            template <typename Type>
            template <typename Subtype>
            void libdsa::structures::tree::BinaryTree<Type>::_checkTypeCompatability(Subtype datum)
            {
                if constexpr (!std::is_same_v<Type, Subtype>)
                {
                    throw std::runtime_error("BinaryTree - Invalid type passed into tree.");
                }
            }

            template <typename Type>
            size_t libdsa::structures::tree::BinaryTree<Type>::Size()
            {
                return this->_size;
            }
        } // tree
    } // structures
} // libdsa

#endif // TREE_H_
/// @}