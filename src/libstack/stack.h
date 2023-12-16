/// @author [Jakob Germann, Software Engineer]
/// @date [2023]
/// @file stack
/// @{

#ifndef STACK_H_
#define STACK_H_

// From C++ STL
#include <iostream>

namespace libdsa
{
    namespace libstructures
    {
        /// @brief Declaration and implementation of the @c Stack class.
        /// @tparam T Templated parameter to allow the container to be used with
        /// any data type.
        template <typename T>
        class Stack
        {
            public:
                /// @brief Constructor
                /// @param size Maximum size of the stack.
                Stack(size_t size);

                /// @brief Destructor
                ~Stack();

                /// @brief Pops an element off the top of the container.
                /// @return The element popped off the stack top.
                T pop();

                /// @brief Pushes a new data element on the top of the stack.
                /// @param element The element being pushed
                void push(T element);

                /// @brief Checks if the stack is empty.
                /// @return Whether the stack is empty.
                bool empty();

            private:
                /// @brief User defined size of the stack.
                size_t _size;

                /// @brief The underlying stack container.
                T *_stack;

                /// @brief Stack pointer.
                int _sp;
        }; // Stack

        template <typename T>
        libdsa::libstructures::Stack<T>::Stack(size_t size) : _size(size)
        {
            this->_sp = -1;
            this->_stack = new T[this->_size];
        }

        template <typename T>
        libdsa::libstructures::Stack<T>::~Stack()
        {
            delete[] _stack;
        }

        template <typename T>
        T libdsa::libstructures::Stack<T>::pop()
        {
            if (this->_sp == -1)
            {
                std::cout << "Stack is empty" << std::endl;
                exit(0);
            }

            return this->_stack[this->_sp--];
        }

        template <typename T>
        void libdsa::libstructures::Stack<T>::push(T element)
        {
            if (this->_sp <= static_cast<int>(this->_size))
            {
                this->_stack[++this->_sp] = element;
            }
            else
            {
                std::cout << "Stack is full" << std::endl;
            }
        }

        template <typename T>
        bool libdsa::libstructures::Stack<T>::empty()
        {
            if (this->_sp == -1)
            {
                return true;
            }
            return false;
        }
        
    } // libstructures
} // libdsa

#endif // STACK_H_

/// @}