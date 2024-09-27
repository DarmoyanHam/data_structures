#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>

namespace deq{

template <typename T, size_t N>
class Deque
{
public:
    using value_type = T;
    using pointer = value_type*;
    using reference = value_type&;
public:
    Deque(int size); //
public:
    void push_front(value_type n); //
    void push_back(value_type n); //
    void pop_front(); //
    void pop_back(); //
    bool isFull(); //
    bool isEmpty(); //
    reference get_front();
    reference get_back();
private:
    value_type arr[N];
    int size;
    int front;
    int rear;
};

}

#include "deque.hpp"

#endif