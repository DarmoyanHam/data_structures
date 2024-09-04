#ifndef __DLIST
#define __DLIST

#include <iostream>

namespace D_LIST{

template <typename T>
struct Node{
    T val;
    Node<T>* next;
    Node<T>* prev;
    Node() : val{0} , next{nullptr} , prev{nullptr} {}
    Node(T data) : val{data} , next{nullptr} , prev{nullptr} {}
};

template <typename T>
class DList{
public:
    DList(); //
    DList(T data); // 
    ~DList(); //
public:
    void push_front(T data); // +
    void pop_front(); // +
    void push_back(T data); // +
    void pop_back(); // +
    void insert_after(Node<T>* prev, T data); // +
    void erase_after(Node<T>* prev); // +
    bool isEmpty() const; // +
    Node<T>* front() const; // +
    Node<T>* back() const; // +
    void reverse(); // +
    void merge(const DList<T>& other); // +
    Node<T>* search(T data) const; // +
    void unique(); // +
    void clear(); //
private:
    Node<T>* head;
    Node<T>* tail;
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const DList<T>& list);

}

#include "double_list.cpp"

#endif