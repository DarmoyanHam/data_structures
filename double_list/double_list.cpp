#ifndef DD
#define DD

#include <iostream>
#include "double_list.h"

template <typename T>
D_LIST::DList<T>::DList()
: head{nullptr}
, tail{nullptr}
{}

template <typename T>
D_LIST::DList<T>::DList(T data)
: head{new Node(data)}
, tail{head}
{}

template <typename T>
D_LIST::DList<T>::~DList()
{
    clear();
}

template <typename T>
void D_LIST::DList<T>::push_front(T data)
{
    if(isEmpty())
    {
        head = new Node(data);
        tail = head;
        return;
    }
    Node<T>* tmp = new Node(data);
    tmp->next = head;
    head->prev = tmp;
    head = tmp;
}

template <typename T>
void D_LIST::DList<T>::pop_front()
{
    if(isEmpty())
    {
        return;
    }
    Node<T>* tmp = head;
    if(head == tail)
    {
        head = nullptr;
        tail = nullptr;
        delete tmp;
        tmp = nullptr;
        return;
    }
    head = head->next;
    head->prev = nullptr;
    delete tmp;
    tmp = nullptr;
}

template <typename T>
void D_LIST::DList<T>::push_back(T data)
{
    if(isEmpty())
    {
        push_front(data);
        return;
    }
    Node<T>* tmp = new Node(data);
    tmp->prev = tail;
    tail->next = tmp;
    tail = tmp;
}

template <typename T>
void D_LIST::DList<T>::pop_back()
{
    if(isEmpty())
    {
        return;
    }
    Node<T>* tmp = tail;
    if(tail == head)
    {
        tail = nullptr;
        head = nullptr;
        delete tmp;
        tmp = nullptr;
        return;
    }
    tail = tail->prev;
    tail->next = nullptr;
    delete tmp;
    tmp = nullptr;
}

template <typename T>
void D_LIST::DList<T>::insert_after(Node<T>* prev, T data)
{
    if(prev == tail)
    {
        push_back(data);
        return;
    }
    Node<T>* tmp = new Node(data);
    tmp->next = prev->next;
    tmp->prev = prev;
    prev->next = tmp;
    tmp->next->prev = tmp;
}

template <typename T>
void D_LIST::DList<T>::erase_after(Node<T>* prev)
{
    if(prev == tail)
    {
        return;
    }
    Node<T>* tmp = prev->next;
    if(tmp == tail)
    {
        pop_back();
        return;
    }
    prev->next = tmp->next;
    tmp->next->prev = prev;
    delete tmp;
    tmp = nullptr;
}

template <typename T>
bool D_LIST::DList<T>::isEmpty() const
{
    return !head;
}

template <typename T>
D_LIST::Node<T>* D_LIST::DList<T>::front() const
{
    return head; 
}

template <typename T>
D_LIST::Node<T>* D_LIST::DList<T>::back() const
{
    return tail; 
}

template <typename T>
D_LIST::Node<T>* D_LIST::DList<T>::search(T data) const
{
    Node<T>* curr = head;
    while(curr)
    {
        if(curr->val == data)
        {
            return curr;
        }
        curr = curr->next;
    }
    return curr;
}

template <typename T>
void D_LIST::DList<T>::reverse()
{
    if(head == tail)
    {
        return;
    }
    Node<T>* tmp = nullptr;
    Node<T>* curr = head;
    while(curr)
    {
        tmp = curr->prev;
        curr->prev = curr->next;
        curr->next = tmp;
        curr = curr->prev;
    }
    tmp = tail;
    tail = head;
    head = tmp;
}

template <typename T>
void D_LIST::DList<T>::merge(const DList<T>& other)
{
    if(other.isEmpty())
    {
        return;
    }
    if(isEmpty())
    {
        head = other.head;
        tail = other.tail;
        return;
    }
    tail->next = other.head;
    other.head->prev = tail;
    tail = other.tail;
}

template <typename T>
void D_LIST::DList<T>::unique()
{
    Node<T>* curr = head;
    while(curr && curr->next)
    {
        while(curr->val == curr->next->val)
        {
            erase_after(curr);
            if(!curr->next)
            {
                return;
            }
        }
        curr = curr->next;
    }
}

template <typename T>
void D_LIST::DList<T>::clear()
{
    while(head != tail)
    {
        head = head->next;
        delete head->prev;
    }
    delete head;
    head = nullptr;
    tail = nullptr;
}

template <typename T>
std::ostream& D_LIST::operator<<(std::ostream& out, const D_LIST::DList<T>& list)
{
    Node<T>* node = list.front();
    while(node)
    {
        out << node->val << " ";
        node = node->next;
    }
    return out;
}

#endif