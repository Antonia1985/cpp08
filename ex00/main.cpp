#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <list>

template <typename T>
void testEasyfind(T &container, int value)
{
    typename T::iterator it = easyfind(container, value);
    if(it != container.end())
        std::cout << "Value found: "<< *it << std::endl;
    else
        std::cout << "Value Not found."<< std::endl;
}

int main()
{

    //test VECTOR
    std::vector<int> v;
    v.push_back(1);
    v.push_back(5);
    v.push_back(9);

    std::vector<int>::iterator it;
    testEasyfind(v, 5);
    testEasyfind(v, 42); 

    //test LIST
    std::list<int> l;
    l.push_back(10);
    l.push_back(50);
    l.push_back(90);
    testEasyfind(l, 50);
    testEasyfind(l, 42);

    //test DEQUE
    std::deque<int> d;
    d.push_back(11);
    d.push_back(15);
    d.push_back(19);
    testEasyfind(d, 15);
    testEasyfind(d, 42);

    return 0;
}