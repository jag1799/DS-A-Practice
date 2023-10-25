#include <array>

namespace libds
{
    template <typename T>
    class LinkedList
    {
    public:
        LinkedList(T data[]);
        LinkedList(T data[], size_t size);

        void append(T datum);
        void print();

    private:
        LinkedList *head;
    };
}