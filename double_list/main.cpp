#include <iostream>
#include "double_list.h"


int main()
{
    D_LIST::DList<int> double_list;
    double_list.push_back(5);
    double_list.push_back(7);
    double_list.push_front(12);
    double_list.push_back(7);
    double_list.pop_front();
    double_list.push_back(16);
    double_list.pop_back();
    double_list.insert_after(double_list.front(), 5);
    double_list.insert_after(double_list.back(), 7);
    double_list.insert_after(double_list.search(7), 10);
    double_list.erase_after(double_list.search(7));
    double_list.reverse();

    D_LIST::DList<int> list;
    list.push_back(11);
    list.push_back(152);
    list.push_back(57);
    list.push_back(0);
    list.push_back(0);

    std::cout << list << std::endl;
    std::cout << double_list << std::endl;

    double_list.merge(list);
    std::cout << double_list << std::endl;

    std::cout << double_list.front()->val << " " << double_list.back()->val << std::endl;

    double_list.unique();
    std::cout << double_list << std::endl;

    double_list.clear();
    std::cout << double_list <<std::endl;

    std::cout << list << std::endl;
    
    //std::cout << double_list.isEmpty() << std::endl;


    return 0;
}