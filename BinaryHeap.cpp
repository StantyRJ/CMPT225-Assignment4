/* 
 * BinaryHeap.cpp
 *
 * Description: ____________ Binary Heap ADT class.
 *
 * Class Invariant:  Always a ____________ Binary Heap.
 * 
 * Author: 
 * Last Modification: Nov. 2023
 *
 */  

#include <iostream>
#include "BinaryHeap.h"  // Header file
#include <tgmath.h>

using std::cout;
using std::endl;
  
template <class ElementType>
BinHeap<ElementType>::BinHeap()
{
    heap = (ElementType*)malloc(sizeof(ElementType*));
}

template <class ElementType>
unsigned int BinHeap<ElementType>::elementLeft(int index) const
{
    return (index * 2) + 1;
}

template <class ElementType>
unsigned int BinHeap<ElementType>::elementRight(int index) const
{
    return (index * 2) + 2;
}

template <class ElementType>
unsigned int BinHeap<ElementType>::elementPrevious(int index) const
{
    return (int)((index-1)/2);
}

template <class ElementType>
unsigned int BinHeap<ElementType>::getElementCount() const
{
    return numElements;
}

template <class ElementType>
bool BinHeap<ElementType>::insert(ElementType &newElement)
{
    heap[numElements] = newElement;

    //sort item into place
    int current_index = numElements;
    if(current_index > 0)
    {
        while(heap[current_index] < heap[elementPrevious(current_index)])
        {
            int temp_index = elementPrevious[current_index];
            ElementType* temp = heap[temp_index];
            heap[temp_index] = heap[current_index];
            current_index = temp_index;
            if(current_index == 0)
                break;
        }
    }

    numElements++;

    //resize array when nessiary
    if(numElements >= pow(2,height))
    {
        height++;
        heap = realloc(heap,pow(2,height) * sizeof(ElementType*));
    }
}

template <class ElementType>
void BinHeap<ElementType>::remove()
{
    ElementType * topElement = heap[0];
    int current_index = 0;
    if(numElements > current_index)
    {
        int left_index = 1;
        int right_index = 2;
        while(heap[current_index] < heap[elementPrevious[current_index]])
        {
            int temp_index = elementPrevious[current_index];
            ElementType* temp = heap[temp_index];
            heap[temp_index] = heap[current_index];
            current_index = temp_index;
            if(current_index == 0)
                break;
        }
    }
}

template <class ElementType>
ElementType & BinHeap<ElementType>::retrieve() const
{
    return heap[0];
}

template <class ElementType>
BinHeap<ElementType>::~BinHeap()
{
    for(int i = 0; i < numElements; i++)
        delete heap[i];
    free(heap);
}
