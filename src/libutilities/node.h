/// @author [Software Engineer]
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
            Node *_next;
            Node *_prev;
            T _datum;

            Node(T datum)
                : _next(nullptr), _prev(nullptr), _datum(datum)
            {
                // Intentionally empty constructor.
            }
        }; // Node

    } // libstructures
} // libdsa

#endif // NODE_H_

/// @}