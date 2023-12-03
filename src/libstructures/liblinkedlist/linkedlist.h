/// Author: [Jakob Germann, Software Engineer]
/// Time: [2023-2024]
/// @name linkedlist
/// @{

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

// From C++ STL
#include <iostream>

// From libstructures
#include <node.h>

/// @brief Class implementation of @c LinkedList class.
namespace libdsa
{
    namespace libstructures
    {
        template <typename T>
        class LinkedList
        {
        public:
            /// @brief Default constructor.
            LinkedList() = default;

            /// @brief Appends a new data instance to the end of the list.
            /// @param datum Data instance to be appended.
            void append(T datum);

            /// @brief Removes a data instance specified by the index.
            /// @param idx Index of data instance to be removed.
            void remove(size_t idx);
            
            /// @brief Inserts a data instance specified by the index.
            /// @param datum Data instance to be inserted.
            /// @param idx Position to insert the data instance.
            void insert(T datum, size_t idx);

            /// @brief Returns the underlying head of the list.
            libdsa::libstructures::Node<T> *getHead();

            /// @brief Get the size of the Linked List.
            /// @return The size of the Linked List.
            size_t getSize();

            /// @brief Prints out the contents of the list to the console.
            void print();

        private:
            libdsa::libstructures::Node<T> *_head = nullptr;
            size_t _size = 0;
        };

        template <typename T>
        void libdsa::libstructures::LinkedList<T>::append(T datum)
        {

            // Fill the head node if it's empty. Otherwise append a new node.
            if (_head == nullptr)
            {
                _head = new libdsa::libstructures::Node<T>(datum);
                _head->_next = _head;
                _head->_prev = _head;
            }
            else
            {
                
                libdsa::libstructures::Node<T> *current = _head;

                // Create the new node
                libdsa::libstructures::Node<T> *newNode = new libdsa::libstructures::Node<T>(datum);

                // Go to the end of the list
                while (current->_next != _head)
                {
                    current = current->_next;
                }

                // Append the new node and set the directional pointers.
                current->_next = newNode;
                newNode->_prev = current;
                newNode->_next = _head;
            }

            ++_size;
        }

        template <typename T>
        libdsa::libstructures::Node<T> *libdsa::libstructures::LinkedList<T>::getHead()
        {
            return this->_head;
        }

        template <typename T>
        void libdsa::libstructures::LinkedList<T>::print()
        {
            libdsa::libstructures::Node<T> *current = _head;

            size_t i = 0;
            while (i < _size)
            {
                std::printf("%c", current->_datum);
                current = current->_next;
                ++i;
            }
            std::printf("\n");
        }

        template <typename T>
        size_t libdsa::libstructures::LinkedList<T>::getSize()
        {
            return _size;
        }

        template <typename T>
        void libdsa::libstructures::LinkedList<T>::remove(size_t idx)
        {
            libdsa::libstructures::Node<T> *current = _head;
            size_t i = 0;

            // Check that the index is within bounds.
            if (i > _size)
            {
                std::cout << "Index out of bounds." << std::endl;
                return;
            }

            while(i != idx)
            {
                current = current->_next;
                ++i;
            }

            current->_prev->_next = current->_next;
            current->_next->_prev = current->_prev;

            current->_next = nullptr;
            current->_prev = nullptr;

            delete current;

            --_size;
        }

        template <typename T>
        void libdsa::libstructures::LinkedList<T>::insert(T datum, size_t idx)
        {
            if (idx >= _size)
            {
                std::cout << "Index out of bounds." << std::endl;
                return;
            }
            else 
            {
                libdsa::libstructures::Node<T> *current = _head;
                size_t i = 0;

                while(i != idx)
                {
                    current = current->_next;
                    ++i;
                }

                libdsa::libstructures::Node<T> *node = new libdsa::libstructures::Node<T>(datum);

                node->_next = current;
                node->_prev = current->_prev;

                current->_prev->_next = node;
                current->_prev = node;

                ++_size;
            }
        }
    } // libstructures
} // libdsa

#endif // LINKEDLIST_H_

/// @}