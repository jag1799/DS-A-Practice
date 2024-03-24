/// @author [Software Engineer]
/// @date [2023-2024]
/// @name linkedlist
/// @{

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

// From C++ STL
#include <iostream>

// From libstructures
#include <node.h>

namespace libdsa
{
    namespace libstructures
    {
        /// @brief Class implementation of @c LinkedList class.
        template <typename T>
        class LinkedList
        {
        public:
            /// @brief Default constructor.
            LinkedList() = default;

            /// @brief Appends a new data instance to the end of the list.
            /// @param datum Data instance to be appended.
            template <typename K>
            void append(K datum);

            /// @brief Removes a data instance specified by the index.
            /// @param idx Index of data instance to be removed.
            void removeByIndex(size_t idx);

            /// @brief Removes a data instance specified by the data element.
            /// @param datum Data instance to be removed.
            template <typename K>
            void removeByData(K datum);

            /// @brief Inserts a data instance in a position specified by the index.
            /// @param datum Data instance to be inserted.
            /// @param idx Position to insert the data instance.
            template <typename K>
            void insert(K datum, size_t idx);

            /// @brief Returns the underlying head of the list.
            libdsa::libstructures::Node<T> *getHead();

            /// @brief Get the size of the Linked List.
            /// @return The size of the Linked List.
            size_t getSize();

            /// @brief Prints out the contents of the list to the console.
            void print();

            /// @brief Operator overload of '[]' to allow for index retrieval.
            /// @param idx The index of the node to retrive.  Same indexing system as with std::array.
            /// @return The underlying data contained within the node.
            T operator[](const size_t idx) const;

        private:
            /// @brief Checks the type of the Linked List and type of the datum being inserted.
            /// @throw runtime_error if types T and K are different.
            template <typename K>
            void checkType(K datum);

            /// @brief Underlying head node of the Linked List.
            libdsa::libstructures::Node<T> *_head = nullptr;

            /// @brief Number of nodes within the list.
            size_t _size = 0;
        };

        template <typename T>
        template <typename K>
        void libdsa::libstructures::LinkedList<T>::append(K datum)
        {
            // Confirm the template types are the same.
            checkType(datum);

            // Fill the head node if it's empty. Otherwise append a new node.
            if (_head == nullptr)
            {
                try
                {
                    _head = new libdsa::libstructures::Node<T>(datum);
                    _head->_next = _head;
                    _head->_prev = _head;
                }
                catch (const std::exception &e)
                {
                    std::cerr << e.what() << '\n';
                }
            }
            else
            {
                try
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
                catch (const std::exception &e)
                {
                    std::cerr << e.what() << '\n';
                }
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
                std::cout << current->_datum << std::endl;
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
        void libdsa::libstructures::LinkedList<T>::removeByIndex(size_t idx)
        {
            libdsa::libstructures::Node<T> *current = _head;

            // Check that the index is within bounds.
            if (idx > _size || idx < 0)
            {
                throw std::runtime_error("Class LinkedList - Index request is out of bounds for current container.");
            }

            try
            {
                for (size_t i = 0; i < idx; ++i)
                {
                    current = current->_next;
                }

                current->_prev->_next = current->_next;
                current->_next->_prev = current->_prev;

                current->_next = nullptr;
                current->_prev = nullptr;

                delete current;

                --_size;
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }
        }

        template <typename T>
        template <typename K>
        void libdsa::libstructures::LinkedList<T>::removeByData(K datum)
        {
            checkType(datum);

            libdsa::libstructures::Node<T> *current = _head;

            while (datum != current->_datum && current->_next != _head)
            {
                current = current->_next;
            }

            if (datum != current->_datum && current->_next == _head)
            {
                std::cout << "Data to remove does not exist." << std::endl;
                return;
            }
            else
            {
                current->_prev->_next = current->_next;
                current->_next->_prev = current->_prev;

                current->_next = nullptr;
                current->_prev = nullptr;

                delete current;
                --_size;
            }
        }

        template <typename T>
        template <typename K>
        void libdsa::libstructures::LinkedList<T>::insert(K datum, size_t idx)
        {
            checkType(datum);

            if (idx >= _size || idx < 0)
            {
                throw std::runtime_error("Class LinkedList - Index request is out of bounds for current container.");
            }
            else
            {
                libdsa::libstructures::Node<T> *current = _head;
                size_t i = 0;

                while (i != idx)
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

        template <typename T>
        T libdsa::libstructures::LinkedList<T>::operator[](const size_t idx) const
        {
            Node<T> *current = this->_head;

            if (this->_size <= idx || idx < 0)
            {
                throw std::runtime_error("Class LinkedList - Index requested is out of bounds for current container.");
            }

            for (size_t i = 0; i < idx; ++i)
            {
                current = current->_next;
            }

            return current->_datum;
        }

        template <typename T>
        template <typename K>
        void libdsa::libstructures::LinkedList<T>::checkType(K datum)
        {
            if constexpr (!std::is_same_v<T, K>)
            {
                throw std::runtime_error("Invalid type being appended.");
            }
        }
    } // libstructures
} // libdsa

#endif // LINKEDLIST_H_

/// @}