#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include "queue.h"

using namespace que;

template <typename T, int N>
Queue<T, N>::Queue()
: size{0}
, front{0}
, rear{0}
{}

template <typename T, int N>
bool Queue<T, N>::isFull()
{
    return size == N;
}

template <typename T, int N>
bool Queue<T, N>::isEmpty()
{
    return size == 0;
}

template <typename T, int N>
void Queue<T, N>::enqueue(value_type n)
{
    if(isFull())
    {
        return;
    }
    arr[rear] = n;
    rear = (rear + 1) % N;
    ++size;
}

template <typename T, int N>
typename Queue<T, N>::value_type Queue<T, N>::dequeue()
{
    if(isEmpty())
    {
        return;
    }
    value_type data = arr[front];
    front = (front + 1) % N;
    --size;
    return data;
}

#endif