#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H
#include "Event.h"



template <class ElementType>
class BinHeap
{
    private:
        ElementType * heap;
        int numElements = 0;
        int height = 0;

    public:

        BinHeap();

        unsigned int elementLeft(int index) const;

        unsigned int elementRight(int index) const;

        unsigned int elementPrevious(int index) const;

        unsigned int getElementCount() const;

        bool insert(ElementType &newElement);

        void remove();

        ElementType & retrieve() const;

        ~BinHeap();
};
#endif