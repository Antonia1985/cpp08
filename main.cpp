#include "MutantStack.hpp"
#include <iterator>
#include <iostream>

int main()
{

   // given test
    std::cout << "---------Given Test---------" << std::endl;
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
    std::cout << std::endl;


    //test const
    std::cout << "---------Test Const Iterator---------" << std::endl;
    const MutantStack<int> constMStack(mstack);
    MutantStack<int>::const_iterator cit = constMStack.begin();
    MutantStack<int>::const_iterator cite = constMStack.end();
    
    while (cit != cite)
    {
        std::cout << *cit << std::endl;
        ++cit;
    }// 5 3 5 737 0

    //test Copy constructor independence
    std::cout << "---------Copy constructor independence---------" << std::endl;
    MutantStack<int> mStack1(mstack);
    mStack1.push(10);
    mStack1.push(20);
    mStack1.push(30);
    
    MutantStack<int>::iterator it1 = mStack1.begin();
    MutantStack<int>::iterator ite1 = mStack1.end();
    std::cout << "----mStack1: " <<std::endl;
    while (it1 != ite1)
    {
        std::cout << *it1 << std::endl;
        ++it1;
    }// 5 3 5 737 0 10 20 30
    
    std::cout << "----mstack: " <<std::endl;
    MutantStack<int>::iterator ito = mstack.begin();
    MutantStack<int>::iterator iteo = mstack.end();
    while (ito != iteo)
    {
        std::cout << *ito << std::endl;
        ++ito;
    }// 5 3 5 737 0
/* 
    // test with list
    std::cout << "---------Test with List---------" << std::endl;
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