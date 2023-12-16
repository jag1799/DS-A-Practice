/// @author [Jakob Germann, Software Engineer]
/// @date [2023]
/// @file node
/// @{

#ifndef NODE_H_
#define NODE_H_

namespace libdsa
{
    namespace libstructures
    {
        template <typename T>
        struct Node
        {
            Node(T datum);
            Node *_next;
            Node *_prev;
            T _datum;
        }; // Node

        template <typename T>
        libdsa::libstructures::Node<T>::Node(T datum)
            : _next(nullptr), _prev(nullptr), _datum(datum)
        {
            // Intentionally empty constructor.
        }

    } // libstructures
} // libdsa

#endif // NODE_H_

/// @}