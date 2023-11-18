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

#include "Queue.h"

//Constructor
Queue::Queue(){}

// Description: Returns true if this Queue is empty, otherwise false.
// Postcondition: This Queue is unchanged by this operation.
// Time Efficiency: O(1)
bool Queue::isEmpty() const
{
    if(numElements == 0)
        return true;
    return false;
}

// Description: Inserts newElement at the "back" of this Queue 
//              (not necessarily the "back" of this Queue's data structure) 
//              and returns true if successful, otherwise false.
// Time Efficiency: O(1)
void Queue::enQueue(Event * newEvent)
{
    Node * newNode = new Node;
    newNode->myEvent = newEvent;
    if(head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    numElements++;
}

// Description: Removes (but does not return) the element at the "front" of this Queue 
//              (not necessarily the "front" of this Queue's data structure).
// Precondition: This Queue is not empty.
// Exception: Throws EmptyDataCollectionException if this Queue is empty.   
// Time Efficiency: O(1) 
void Queue::deQueue()
{
    if(head != nullptr)
    {
        Node * temp = head;
        head = head->next;
        delete temp;
    }
    else
        throw EmptyDataCollectionException("The collection is empty cannot deQueue");
}

// Description: Returns (but does not remove) the element at the "front" of this Queue
//              (not necessarily the "front" of this Queue's data structure).
// Precondition: This Queue is not empty.
// Postcondition: This Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Queue is empty.
// Time Efficiency: O(1)
Event * Queue::peek() const
{
    if(head != nullptr)
        return head->myEvent;
    else
        throw EmptyDataCollectionException("The collection is empty cannot peek");
}

//Destructor
Queue::~Queue()
{
    Node * cur = head;
    if(head != nullptr)
    {
        while(cur != nullptr)
        {
            Node * temp = cur;
            cur = cur->next;
            delete temp;
        }
    }
}

