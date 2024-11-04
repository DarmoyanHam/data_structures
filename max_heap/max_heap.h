#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <iostream>
#include <vector>

template <typename T>
class MaxHeap {
public:
    using value_type = T;
    using reference = value_type&;
    using pointer = value_type*;
public:
    MaxHeap(int); //
public:
    value_type top() const; //
    value_type pop(); //
    void push(value_type);
private:
    void heapify(int); //
private:
    std::vector<value_type> heap;
    int size;
    int capacity;
};

#include "max_heap.hpp"

#endif