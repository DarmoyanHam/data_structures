#include <iostream>
#include "vector.h"

template <typename T>
Vector<T>::Vector()
: size(0)
, cap(0)
, arr(nullptr)
{}

template <typename T>
Vector<T>::Vector(std::size_t s)
: cap(s)
, size(s)
, arr(new T[cap])
{}

template <typename T>
Vector<T>::Vector(std::size_t s, T val)
: cap(s)
, size(s)
, arr(new T[cap])
{
    for(std::size_t i = 0; i < size; ++i)
    {
        arr[i] = val;
    }
}

template <typename T>
Vector<T>::Vector(const Vector& rhv)
: cap(rhv.cap)
, size(rhv.size)
, arr(new T[cap])
{
    for(std::size_t i = 0; i < size; ++i)
    {
        arr[i] = rhv.arr[i];
    }
}

template <typename T>
Vector<T>::Vector(Vector&& rhv)
: cap(std::move(rhv.cap))
, size(std::move(rhv.size))
, arr(std::move(rhv.arr))
{
    rhv.cap = 0;
    rhv.size = 0;
    rhv.arr = nullptr;
    
}

template <typename T>
Vector<T>::~Vector()
{
    clear();
}

template <typename T>
const Vector<T>& Vector<T>::operator=(const Vector& rhv)
{
    if(this != &rhv)
    {
        delete[] arr;
        arr = new T[rhv.cap];
        for(std::size_t i = 0; i < rhv.size; ++i)
        {
            arr[i] = rhv.arr[i];
        }
        size = rhv.size;
        cap = rhv.cap;
    }
    return *this;
}

template <typename T>
const Vector<T>& Vector<T>::operator=(Vector&& rhv)
{
    if(this != &rhv)
    {
        delete[] arr;
        arr = std::move(rhv.arr);
        size = std::move(rhv.size);
        cap = std::move(rhv.cap);
        
        rhv.size = 0;
        rhv.cap = 0;
        rhv.arr = nullptr;
    }
    return *this;
}

template <typename T>
void Vector<T>::reserve(std::size_t n)
{
    resize(n);
}

template <typename T>
std::size_t Vector<T>::sizee() const
{
    return size;
}

template <typename T>
std::size_t Vector<T>::capacity() const
{
    return cap;
}

template <typename T>
bool Vector<T>::include(T val) const
{
    for(std::size_t i = 0; i < size; ++i)
    {
        if(arr[i] == val)
        {
            return true;
        }
    }
    return false;
}

template <typename T>
void Vector<T>::insert(T val, int pos)
{
    if(pos < 0 || pos > size)
    {
        throw std::out_of_range("U have no such index");
    }
    if(pos == size)
    {
        push_back(val);
    }
    else
    {
        if(size == cap)
        {
            resize(cap * 2);
        }
        ++size;
        for(int i = size; i > pos; --i)
        {
            arr[i] = arr[i - 1];
        }
        arr[pos] = val;
    }
}

template <typename T>
void Vector<T>::push_back(T val)
{
    if(!arr)
    {
        arr = new T(val);
        size = 1;
        cap = 1;
        return;
    }
    if(isEmpty())
    {
        ++size;
        arr[0] = val;
        return;
    }
    if(cap == size)
    {
        resize(cap * 2);
    }
    ++size;
    arr[size] = val;
}

template <typename T>
void Vector<T>::pop_back()
{
    if(size > 0)
    {
        --size;
    }
}

template <typename T>
void Vector<T>::remove(int pos)
{
    if(pos < 0 || pos >= size)
    {
        throw std::out_of_range("there is no such index");
    }
    for(std::size_t i = pos; i < size - 1; ++i)
    {
        arr[i] = arr[i + 1];
    }
    --size;
}

template <typename T>
T& Vector<T>::operator[](int pos)
{
    return arr[pos];
}

template <typename T>
bool Vector<T>::isEmpty() const
{
    return size == 0;
}

template <typename T>
void Vector<T>::clear()
{
    delete[] arr;
    size = 0;
    cap = 0;
    arr = nullptr;
}

template <typename T>
void Vector<T>::shrink_to_fit()
{
    resize(size);
}

template <typename T>
void Vector<T>::resize(int s)
{
    T* tmp = new T[s];
    for(std::size_t i = 0; i < size; ++i)
    {
        tmp[i] = arr[i];
    }
    delete[] arr;
    arr = tmp;
    cap = s;
    tmp = nullptr;
}

int main()
{


    return 0;
}