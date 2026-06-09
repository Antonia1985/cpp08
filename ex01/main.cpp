#include "Span.hpp"
#include <iostream>
#include <algorithm>
#include <list>
#include <deque>

void printNumber(int n)
{
    std::cout << n << std::endl;
}

int main()
{
    //Given test
    std::cout << "--------GIVEN TEST--------" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << std::endl;


    //shortestSpan() with 0 elements
    std::cout << "--------shortestSpan() with 0 elements--------" << std::endl;
    Span empty = Span(5);   
    try 
    {
        std::cout << empty.shortestSpan() << std::endl;
    }
    catch(const  std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }   
    std::cout << std::endl;


    //shortestSpan() with 1 elements
    std::cout << "--------shortestSpan() with 1 element--------" << std::endl;
    Span one = Span(5);
    one.addNumber(6);
    try 
    {
        std::cout << one.shortestSpan() << std::endl;
    }
    catch(const  std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }   
    std::cout << std::endl;


    // addNumber() when full
    std::cout << "--------addNumber() when full--------" << std::endl;
    Span full = Span(3);
    full.addNumber(1);
    full.addNumber(2);
    full.addNumber(3);
    try 
    {
        full.addNumber(4);
    }
    catch(const  std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }   
    std::cout << std::endl;


    // addRange() when the range is too large
    std::cout << "--------addRange() when the range is too large--------" << std::endl;
    Span sp5 = Span(5);
    sp5.addNumber(1);
    sp5.addNumber(2);
    sp5.addNumber(3);

    std::vector<int> v5;
    v5.push_back(1);
    v5.push_back(2);
    v5.push_back(3);
    v5.push_back(4);
    v5.push_back(5);   
    try 
    {
        sp5.addRange(v5.begin(), v5.end());
    }
    catch(const  std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }   
    std::cout << std::endl;



    //Test addRange by vector
    std::cout << "--------TEST ADDRANGE BY VECTOR--------" << std::endl;
    Span sp1 = Span(10);
    sp1.addNumber(0);
    sp1.addNumber(2);

    std::vector<int> v1;
    v1.push_back(3);
    v1.push_back(2);
    v1.push_back(150);
    sp1.addRange(v1.begin(), v1.end());
    std::cout << sp1.shortestSpan() << std::endl;
    std::cout << sp1.longestSpan() << std::endl;
    std::cout << std::endl;


    //Test addRange by list
    std::cout << "--------TEST ADDRANGE BY LIST--------" << std::endl;
    Span sp2 = Span(100000);
    sp2.addNumber(0);
    sp2.addNumber(1);

    std::list<int> l;
    int num = 2;
    for(int i = 0; i < 99998; i++)
    {
        l.push_back(num);
        num += 1;
    }    
    sp2.addRange(l.begin(), l.end());
    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;
    std::cout << std::endl;


    //Test addRange by deque
    std::cout << "--------TEST ADDRANGE BY DEQUE--------" << std::endl;
    Span sp3 = Span(10);
    sp3.addNumber(0);
    sp3.addNumber(10);

    std::deque<int> q;
    num = 20;
    for(int i = 0; i < 8; i++)
    {
        q.push_back(num);
        num += 10;
    }
    sp3.addRange(q.begin(), q.end());
    std::cout << sp3.shortestSpan() << std::endl;
    std::cout << sp3.longestSpan() << std::endl;
    std::cout << std::endl;

    //Test InvalidRange by vector
    std::cout << "--------TEST INVALIDRANGE BY VECTOR--------" << std::endl;
    Span sp4 = Span(10);
    sp4.addNumber(1);
    sp4.addNumber(2);

    std::vector<int> v4;
    v4.push_back(3);
    v4.push_back(4);
    v4.push_back(5);
    try 
    {
        sp1.addRange(v4.end(), v4.begin());
    }
    catch(const  std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }   
    std::cout << std::endl;    

    return 0;
}
