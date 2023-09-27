#include "IntegerArrayQueue.h"

// returns a bool value: true if queue is non-full prior to enqueuing the value
// : false if the queue is already full in which case the value is not enqueued.
bool IntegerArrayQueue::enqueue(int value) {
    if (((back == (size - 2)) && (front == 0)) ||
        ((back == size - 1) && (front == 1)) || (back == front - 2)) {
        return false;
    }
    back = (back + 1) % size;
    array[back] = value;

    printArrayQueue();
    return true;
}

// returns the dequeued value if the queue is non-empty or 0 if the queue is
// empty
int IntegerArrayQueue::dequeue() {
    int returnValue;
    if ((back + 1) % size == front) {
        return 0;
    }

    returnValue = array[front];
    front = (front + 1) % size;
    return returnValue;
}