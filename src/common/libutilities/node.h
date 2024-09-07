/// @author [Software Engineer]
/// @date [2023,2024]
/// @file node
/// @{

#ifndef NODE_H_
#define NODE_H_

// From C++ STL
#include <vector>

namespace libdsa
{
    namespace structures
    {
        namespace utilities
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


            template <typename type>
            struct TreeNode
            {
                std::vector<TreeNode*> children;
                type _datum;

                TreeNode(type datum) : _datum(datum)
                {
                    // Intentionally empty constructor
                }
            }; // TreeNode
        }

    } // structures
} // libdsa

#endif // NODE_H_

/// @}