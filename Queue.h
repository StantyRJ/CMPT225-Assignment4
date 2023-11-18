/*
 * Queue.cpp
 *
 * Description: a double headed linked list based queue
 *
 * Class invarient: always a queue
 *
 * Author: Ryan Hargrave
 * Last Modified: Nov.17 2023
 */

#ifndef Queue_H
#define Queue_H

#include "Event.h"
#include <iostream>
#include "EmptyDataCollectionException.h"

struct Node
{
    Event * myEvent;
    Node * next = nullptr;
};

class Queue
{
    private:
        Node * head = nullptr;
        Node * tail = nullptr;
        int numElements = 0;

    public:

        //Constructor
        Queue();

        // Description: Returns true if this Queue is empty, otherwise false.
        // Postcondition: This Queue is unchanged by this operation.
        // Time Efficiency: O(1)
        bool isEmpty() const;

        // Description: Inserts newElement at the "back" of this Queue 
        //              (not necessarily the "back" of this Queue's data structure) 
        //              and returns true if successful, otherwise false.
        // Time Efficiency: O(1)
        void enQueue(Event * newEvent);

        // Description: Removes (but does not return) the element at the "front" of this Queue 
        //              (not necessarily the "front" of this Queue's data structure).
        // Precondition: This Queue is not empty.
        // Exception: Throws EmptyDataCollectionException if this Queue is empty.   
        // Time Efficiency: O(1) 
        void deQueue();


        // Description: Returns (but does not remove) the element at the "front" of this Queue
        //              (not necessarily the "front" of this Queue's data structure).
        // Precondition: This Queue is not empty.
        // Postcondition: This Queue is unchanged by this operation.
        // Exception: Throws EmptyDataCollectionException if this Queue is empty.
        // Time Efficiency: O(1)
        Event * peek() const;

        //Destructor
        ~Queue();
};
#endif