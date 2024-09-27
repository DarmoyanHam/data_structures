#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include "stack.h"

using namespace stack;

template <typename T, int N>
Stack<T, N>::Stack()
: mtop{-1}
{}

template <typename T, int N>
bool Stack<T, N>::isEmpty()
{
    if(mtop >= N - 1)
    {
        std::cout << "stackoverflow" << std::endl;
        return false;
    }
    return mtop < 0;
}

template <typename T, int N>
bool Stack<T, N>::isFull()
{
    return mtop >= N - 1;
}

template <typename T, int N>
void Stack<T, N>::push(value_type n)
{
    if(isFull())
    {
        return;
    }
    ++mtop;
    arr[mtop] = n;
}

template <typename T, int N>
void Stack<T, N>::pop()
{
    if(isEmpty())
    {
        return;
    }
    --mtop;
}

template <typename T, int N>
typename Stack<T, N>::reference Stack<T, N>::top()
{
    if(isEmpty())
    {
        throw std::invalid_argument("there is no element in stack");
    }
    return arr[mtop--];
}

#endif