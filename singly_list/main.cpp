#include "singly_list.h"
#include <iostream>


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

    return 0;
}