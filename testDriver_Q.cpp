#include "Event.h"
#include "EmptyDataCollectionException.h"
#include "BinaryHeap.h"
#include <iostream>
#include <ostream>

using std::cout;
using std::endl;


int main()
{
    BinHeap<Event>* BH = new BinHeap<Event>();

    Event *newEvent = new Event('a',1);
    BH->insert(*newEvent);

    BH->getElementCount();

    cout << BH->retrieve().getTime();

    delete BH;

    return 0;
}