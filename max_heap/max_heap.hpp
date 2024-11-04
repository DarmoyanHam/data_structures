#ifndef MAXHEAP_HPP
#define MAXHEAP_HPP

#include <iostream>
#include <vector>
#include "max_heap.h"

template <typename T>
MaxHeap<T>::MaxHeap(int cap)
: size{0}
, capacity{cap}
{
    heap.resize(capacity);
}

template <typename T>
void MaxHeap<T>::heapify(int i)
{
    int largest = i; 
    int l = i * 2 + 1;
    int r = i * 2 + 2;

    if(l < size && heap[l] > heap[largest])
    {
        largest = l;
    }
    if(r < size && heap[r] > heap[largest])
    {
        largest = r;
    }
    if(i != largest)
    {
        std::swap(heap[i], heap[largest]);
        heapify(largest);
    }
}

template <typename T>
typename MaxHeap<T>::value_type MaxHeap<T>::top() const
{
    if(size == 0)
    {
        return -1;
    }
    return heap[0];
}

template <typename T>
typename MaxHeap<T>::value_type MaxHeap<T>::pop()
{
    if(size == 0)
    {
        return -1;
    }
    if(size == 1)
    {
        --size;
        return heap[0];
    }

    value_type root = heap[0];
    heap[0] = heap[size - 1];
    --size;
    heapify(0);
    return root;
}

template <typename T>
void MaxHeap<T>::push(value_type val)
{
    if(size == capacity)
    {
        capacity *= 2;
        heap.resize(capacity);
    }
    ++size;
    heap[size - 1] = val;
    int i = size - 1;
    while(i != 0 && heap[i] > heap[(i - 1) / 2])
    {
        std::swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

#endif