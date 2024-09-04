#ifndef LIST
#define LIST

#include <iostream>

namespace LST{

template <typename T>
struct Node {
    T val;
    Node* next;
    Node() : next{nullptr} , val{0} {}
    explicit Node(T data) : val{data} , next{nullptr} {}
    explicit Node(T data, Node* node) : val{data} , next{node} {}
};

template <typename T>
class SList {
public:
    SList(); //
    SList(T data); //
    ~SList(); //
public:
    void push_front(T data); //+
    void pop_front(); //+
    void insert_after(Node<T>* prev, T data); //+
    void erase_after(Node<T>* prev); //+
    void clear(); //+
    bool isEmpty() const;// +
    Node<T>* front() const; // + 
    Node<T>* search(T key) const; // +
    void reverse(); // +
    void merge(SList& other); //
    //void print_list(); //
    //void sort();
    void unique();  // +
private:
    Node<T>* head;
};

template <typename T>
std::ostream& operator<<(std::ostream&, const SList<T>&); //

}

//#include "singly_list.cpp"

#endif