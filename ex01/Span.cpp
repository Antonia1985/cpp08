#include "Span.hpp"
#include <algorithm>

Span::Span() : N(0)
{
    v.reserve(N);
};

Span::Span(unsigned int n) : N(n)
{
    v.reserve(N);
};

Span::Span(const Span& other) : N(other.N),  v(other.v){};

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        N = other.N;
        v.clear();
        v = other.v;
    }
    return (*this);
}

Span::~Span(){};

void Span::addNumber(int value)
{
    if (v.size() >= N)
        throw FullContainer();

    v.push_back(value);
}

unsigned int Span::shortestSpan() const
{
    if (v.size() == 0 || v.size() == 1 )
        throw NotEnoughElementsToCompare();
    
    std::vector<int> sorted = v;
    std::sort(sorted.begin(), sorted.end());
    //std::vector<int>::iterator it;
    std::vector<int>::size_type end = sorted.size() - 1;
    std::vector<int>::size_type start = 0;
    unsigned int shortest;
    unsigned int diff;
    while (start < end)
    {
        diff = sorted[start+1] - sorted[start];
        
        if(start == 0) //runs only for the first subtraction
            shortest = diff;
        else if (diff < shortest)
            shortest = diff;
        
        start++;
    }

    return shortest;
}

unsigned int Span::longestSpan() const
{
    if (v.size() == 0 || v.size() == 1 )
        throw NotEnoughElementsToCompare();

    std::vector<int>::const_iterator max = std::max_element(v.begin(), v.end());
    std::vector<int>::const_iterator min = std::min_element(v.begin(), v.end());

    unsigned int longest = *max - *min;
    return longest;
}