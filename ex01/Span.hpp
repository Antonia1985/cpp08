#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <iterator>
#include <cstddef>

class InvalidRange : public std::exception
{
    public:
        virtual const char * what() const throw()
        {
            return "Invalid / backward range.";
        }
};

class FullContainer : public std::exception
{
    public:
        virtual const char * what() const throw()
        {
            return "Container is already full.";
        }
};

class NotEnoughElementsToCompare : public std::exception
{
    public:
        virtual const char * what() const throw()
        {
            return "Not enough elements to calculate span.";
        }
};

class Span
{
    private:
        unsigned int N;
        std::vector<int> v;
        

    public:
        Span();
        Span(unsigned int n);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int value);
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;

        template <typename Iterator>
        void addRange(Iterator first, Iterator last)
        {
            std::ptrdiff_t rangeSize = std::distance(first, last); //returns a signed type but v.size() and N are unsigned
            if (rangeSize < 0)
                throw InvalidRange();
            
            if (static_cast<std::size_t>(rangeSize) + v.size() > static_cast<std::size_t>(N))
                throw FullContainer();

            v.insert(v.end(), first, last);
        }
};

 


#endif