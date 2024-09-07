/// @author [Software Engineer]
/// @date [2023-2024]
/// @name linkedlist
/// @{

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

// From C++ STL
#include <iostream>

// From common
#include <logger.h>

// From structures
#include <node.h>

namespace libdsa
{
    namespace structures
    {
        /// @brief Class implementation of a @c LinkedList class.
        template <typename T>
        class LinkedList
        {
        public:
            /// @brief Default constructor.
            // LinkedList() = default;

            LinkedList();

            /// @brief Appends a new data instance to the end of the list.
            ///
            /// @param datum Data instance to be appended.
            template <typename K>
            void append(K datum);

            /// @brief Checks if the data instance exists in the Linked List
            ///
            /// @param item Data instance to check for.
            ///
            /// @note This method uses a Dual-End search.  Two pointers search starting from
            ///       each end.
            ///
            /// @return True if the item is found, false otherwise.
            template <typename K>
            bool exists(const K item);

            /// @brief Removes a data instance specified by the index.
            ///
            /// @param idx Index of data instance to be removed.
            void removeByIndex(size_t idx);

            /// @brief Removes a data instance specified by the data element.
            ///
            /// @param datum Data instance to be removed.
            template <typename K>
            void removeByData(K datum);

            /// @brief Inserts a data instance in a position specified by the index.
            ///
            /// @param datum Data instance to be inserted.
            /// @param idx Position to insert the data instance.
            template <typename K>
            void insert(K datum, size_t idx);

            /// @brief Returns the underlying head of the list.
            libdsa::structures::utilities::Node<T> *getHead();

            /// @brief Get the size of the Linked List.
            ///
            /// @return The size of the Linked List.
            size_t getSize();

            /// @brief Prints out the contents of the list to the console.
            void print();

            /// @brief Operator overload of '[]' to allow for index retrieval.
            ///
            /// @param idx The index of the node to retrive.  Same indexing system as with std::array.
            ///
            /// @return The underlying data contained within the node.
            T operator[](const size_t idx) const;

        private:
            /// @brief Checks the type of the Linked List and type of the datum being inserted.
            ///
            /// @param datum A data instance we want to compare with the type of the List for compatability.
            ///
            /// @throw runtime_error if types T and K are different.
            template <typename K>
            void checkType(K datum);

            /// @brief Underlying head node of the Linked List.
            libdsa::structures::utilities::Node<T> *_head = nullptr;

            /// @brief Number of nodes within the list.
            size_t _size = 0;

            libdsa::common::Logger *_logger;
        };

        template <typename T>
        libdsa::structures::LinkedList<T>::LinkedList()
        {
            this->_logger = new libdsa::common::Logger();
        }

        template <typename T>
        template <typename K>
        void libdsa::structures::LinkedList<T>::append(K datum)
        {
            // Confirm the template types are the same.
            checkType(datum);

            // Fill the head node if it's empty. Otherwise append a new node.
            if (_head == nullptr)
            {
                try
                {
                    _head = new libdsa::structures::utilities::Node<T>(datum);
                    _head->_next = _head;
                    _head->_prev = _head;
                }
                catch (const std::exception &e)
                {
                    this->_logger->log("Failure to set data to head", libdsa::common::LogLevel::LOG_CRITICAL);
                    std::cerr << e.what() << '\n';
                }
            }
            else
            {
                try
                {
                    // Get the last node of the linked list
                    libdsa::structures::utilities::Node<T> *lastNode = _head->_prev;

                    // Create the new node
                    libdsa::structures::utilities::Node<T> *newNode = new libdsa::structures::utilities::Node<T>(datum);

                    // Append the new node to the end of the list.
                    newNode->_next = _head;
                    newNode->_prev = lastNode;

                    // Connect the old last node to the new last node.
                    lastNode->_next = newNode;

                    // Connect the head previous ptr to the new last node.
                    _head->_prev = newNode;
                }
                catch (const std::exception &e)
                {
                    this->_logger->log("Failure in appending a new node past head.", libdsa::common::LogLevel::LOG_CRITICAL);
                    std::cerr << e.what() << '\n';
                }
            }

            ++_size;
        }

        template <typename T>
        libdsa::structures::utilities::Node<T> *libdsa::structures::LinkedList<T>::getHead()
        {
            return this->_head;
        }

        template <typename T>
        void libdsa::structures::LinkedList<T>::print()
        {
            libdsa::structures::utilities::Node<T> *current = _head;

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
        size_t libdsa::structures::LinkedList<T>::getSize()
        {
            return _size;
        }

        template <typename T>
        void libdsa::structures::LinkedList<T>::removeByIndex(size_t idx)
        {
            libdsa::structures::utilities::Node<T> *current = _head;

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
        void libdsa::structures::LinkedList<T>::removeByData(K datum)
        {
            checkType(datum);

            libdsa::structures::utilities::Node<T> *current = _head;

            while (datum != current->_datum && current->_next != _head)
            {
                current = current->_next;
            }

            if (datum != current->_datum && current->_next == _head)
            {
                this->_logger->log("Data to remove does not exist\n", libdsa::common::LogLevel::LOG_WARNING);
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
        void libdsa::structures::LinkedList<T>::insert(K datum, size_t idx)
        {
            checkType(datum);

            if (idx >= _size || idx < 0)
            {
                throw std::runtime_error("Class LinkedList - Index request is out of bounds for current container.");
            }
            else
            {
                libdsa::structures::utilities::Node<T> *current = _head;
                size_t i = 0;

                while (i != idx)
                {
                    current = current->_next;
                    ++i;
                }

                libdsa::structures::utilities::Node<T> *node = new libdsa::structures::utilities::Node<T>(datum);

                node->_next = current;
                node->_prev = current->_prev;

                current->_prev->_next = node;
                current->_prev = node;

                ++_size;
            }
        }

        template <typename T>
        T libdsa::structures::LinkedList<T>::operator[](const size_t idx) const
        {
            if (this->_size <= idx || idx < 0)
            {
                throw std::runtime_error("Class LinkedList - Index requested is out of bounds for current container.");
            }
            
            utilities::Node<T> *current = this->_head;

            for (size_t i = 0; i < idx; ++i)
            {
                current = current->_next;
            }

            return current->_datum;
        }

        template <typename T>
        template <typename K>
        bool libdsa::structures::LinkedList<T>::exists(const K item)
        {
            checkType(item);

            // Declare forward and backward search pointers.
            utilities::Node<T> *forward = this->_head;
            size_t forwardIdx = 0;
            utilities::Node<T> *backward = this->_head;
            size_t backwardIdx = this->getSize();

            bool found = false;

            // Start the search from both ends.  If the indexes of both pointers cross over each other,
            // the element does not exist in the list, so break.
            while (found == false)
            {
                if (forward->_datum == item || backward->_datum == item)
                {
                    found = true;
                }
                else if (forwardIdx > backwardIdx)
                {
                    break;
                }
                
                ++forwardIdx;
                --backwardIdx;
                forward = forward->_next;
                backward = backward->_prev;
            }

            return found;
        }

        template <typename T>
        template <typename K>
        void libdsa::structures::LinkedList<T>::checkType(K datum)
        {
            if constexpr (!std::is_same_v<T, K>)
            {
                throw std::runtime_error("Invalid type passed into Linked List.");
            }
        }
    } // structures
} // libdsa

#endif // LINKEDLIST_H_

/// @}