#ifndef DEQUE_HPP
#define DEQUE_HPP

#include <iostream>
#include "deque.h"

using namespace deq;

template <typename T, size_t N>
Deque<T, N>::Deque(int size)
: size{size}
, front{-1}
, rear{-1}
{}

template <typename T, size_t N>
void Deque<T, N>::push_front(value_type n)
{
    if(isFull())
    {
        throw std::out_of_range("deque is full");
    }

    if(front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if(front == 0)
    {
        front = size - 1;
    }
    else
    {
        --front;
    }
    arr[front] = n;
}

template <typename T, size_t N>
void Deque<T, N>::push_back(value_type n)
{
    if(isFull())
    {
        throw std::out_of_range("deque is full");
    }

    if(front == -1)
    {
        rear = 0;
        front = 0;
    }
    else if(rear == size - 1)
    {
        rear = 0;
    }
    else
    {
        ++rear;
    }
    arr[rear] = n;
}

template <typename T, size_t N>
void Deque<T, N>::pop_front()
{
    if(isEmpty())
    {
        throw std::out_of_range("deque is empty");
    }

    if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        if(front == size - 1)
        {
            front = 0;
        }
        else
        {
            ++front;
        }
    }
}

template <typename T, size_t N>
void Deque<T, N>::pop_back()
{
    if(isEmpty())
    {
        throw std::out_of_range("deque is empty");
    }

    if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        if(rear == 0)
        {
            rear = size - 1;
        }
        else
        {
            --rear;
        }
    }
}

template <typename T, size_t N>
bool Deque<T, N>::isEmpty()
{
    return front == -1;
}

template <typename T, size_t N>
bool Deque<T, N>::isFull()
{
    return (front == 0 && rear == size - 1) || (front - rear == 1);
}

template <typename T, size_t N>
typename Deque<T, N>::reference Deque<T, N>::get_front()
{
    if(isEmpty())
    {
        throw std::invalid_argument("empty");
    }
    return arr[front];
}

template <typename T, size_t N>
typename Deque<T, N>::reference Deque<T, N>::get_back()
{
    if(isEmpty() || rear < 0)
    {
        throw std::invalid_argument("empty");
    }
    return arr[rear];
}

#endif