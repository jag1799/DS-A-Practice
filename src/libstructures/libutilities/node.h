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
        };

        template <typename T>
        libdsa::libstructures::Node<T>::Node(T datum)
            : _next(nullptr), _prev(nullptr), _datum(datum)
        {
            // Intentionally empty constructor.
        }

    }
}