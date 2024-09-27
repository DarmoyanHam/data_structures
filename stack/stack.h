#ifndef STACK_H
#define STACK_H

#include <iostream>

namespace stack{

template <typename T, int N = 100>
class Stack{
public:
    using value_type = T;
    using pointer = value_type*;
    using reference = value_type&;
public:
    Stack();
public:
    bool isEmpty();
    bool isFull();
    void push(value_type n);
    void pop();
    reference top();
private:
    int arr[N];
    int mtop;
};

}

#include "stack.hpp"

#endif