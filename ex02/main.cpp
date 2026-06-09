#include "MutantStack.hpp"
#include <iterator>
#include <iostream>

int main()
{

   // given test
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    
    std::cout << mstack.top() << std::endl; //17
    mstack.pop();
    std::cout << mstack.size() << std::endl; // 1

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }// 5 3 5 737 0
    std::stack<int> s(mstack);
    // 
    std::cout << s.size() << std::endl; //5

/* 
    // test with list
    Mutantlist<int> mlist;
    mlist.push_back(5);
    mlist.push_back(17);
    
    std::cout << mlist.back() << std::endl; //17
    mlist.pop_back();
    std::cout << mlist.size() << std::endl; // 1

    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    //[...]
    mlist.push_back(0);
    Mutantlist<int>::iterator it = mlist.begin();
    Mutantlist<int>::iterator ite = mlist.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }// 5 3 5 737 0
    std::list<int> s(mlist);
    // 
    std::cout << s.size() << std::endl; //5
*/

    return 0;
}