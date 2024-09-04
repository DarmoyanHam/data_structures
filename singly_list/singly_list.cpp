#include "singly_list.h"
#include <iostream>

using namespace LST;

template <typename T>
std::ostream& LST::operator<<(std::ostream& out, const SList<T>& list)
{
    Node<T>* curr = list.front();
    while(curr)
    {
        out << curr->val << " ";
        curr = curr->next;
    }
    return out;
}

template <typename T>
SList<T>::SList()
: head{nullptr} 
{}

template <typename T>
SList<T>::SList(T data)
: head{new Node(data)}
{}

template <typename T>
SList<T>::~SList()
{
    clear();
}

template <typename T>
void SList<T>::push_front(T data)
{
    Node<T>* node = new Node(data);
    node->next = head;
    head = node;
}

template <typename T>
void SList<T>::pop_front()
{
    if(isEmpty())
    {
        return;
    }
    Node<T>* tmp = head;
    head = head->next;
    delete tmp;
    tmp = nullptr;
}

template <typename T>
bool SList<T>::isEmpty() const
{
    return !head;
}

template <typename T>
Node<T>* SList<T>::front() const
{
    return head;
}

template <typename T>
void SList<T>::insert_after(Node<T>* prev, T data)
{
    if(!prev)
    {
        return;
    }
    Node<T>* tmp = new Node(data);
    tmp->next = prev->next;
    prev->next = tmp;
}

template <typename T>
void SList<T>::erase_after(Node<T>* prev)
{
    if(!prev || !(prev->next))
    {
        return;
    }
    Node<T>* tmp = prev->next;
    prev->next = tmp->next;
    delete tmp;
    tmp = nullptr;
}

template <typename T>
Node<T>* SList<T>::search(T key) const
{
    Node<T>* curr = head;
    while(curr != nullptr && curr->val != key)
    {
        curr = curr->next;
    }
    return curr;
}

template <typename T>
void SList<T>::clear()
{
    Node<T>* tmp;
    while(head)
    {
        tmp = head;
        head = head->next;
        delete tmp;
    }
}

template <typename T>
void SList<T>::reverse()
{
    Node<T>* curr = head;
    Node<T>* prev = nullptr;
    Node<T>* next = nullptr;
    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

template <typename T>
void SList<T>::merge(SList& other)
{
    Node<T>* curr = head;
    while(curr->next)
    {
        curr = curr->next;
    }
    curr->next = other.head;
}

template <typename T>
void SList<T>::unique()
{
    Node<T>* curr = head;
    while(curr && curr->next)
    {
        while(curr->val == curr->next->val)
        {
            erase_after(curr);
        }
        curr = curr->next;
    }
}


int main()
{
    SList<int> list;
    list.push_front(5);
    list.push_front(3);
    list.push_front(3);
    list.push_front(11);
    list.push_front(11);
    list.push_front(11);
    list.push_front(21);

    std::cout << list << std::endl;

    list.insert_after(list.search(3), 15);
    std::cout << list << std::endl;

    list.erase_after(list.search(3));
    std::cout << list << std::endl;

    list.unique();
    std::cout << list << std::endl;

    list.pop_front();
    std::cout << list << std::endl;

    list.erase_after(list.search(11));
    std::cout << list << std::endl;

    std::cout << list.isEmpty() << std::endl;

    list.insert_after(list.front(), 11);
    std::cout << list << std::endl;

    list.reverse();
    std::cout << list << std::endl;

    SList<int> list2;
    list2.push_front(1);
    list2.push_front(16);

    std::cout << list2 << std::endl;

    list.merge(list2);
    std::cout << list << std::endl;

    list.clear();
    std::cout << list;

    std::cout << list2;

    
    return 0;
}