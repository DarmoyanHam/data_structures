#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

namespace que{

template <typename T, int N>
class Queue{
public:
    using value_type = T;
    using pointer = T*;
    using reference = T&;
public:
    Queue();
public:
    void enqueue(value_type n);
    value_type dequeue();
    bool isEmpty();
    bool isFull();
private:
    value_type arr[N];
    int front;
    int rear;
    int size;
};

}

#include "queue.hpp"

#endif