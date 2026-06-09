#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() : std::stack<T>(){}
        MutantStack(const MutantStack& other) : std::stack<T>(other){}
        MutantStack& operator=(const MutantStack& other)
        {
            if(this != &other)
                std::stack<T>::operator=(other);
            return *this;
        }
        ~MutantStack(){}

        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;

        iterator begin()
        {
            return this->c.begin();
        }

        iterator end()
        {
            return this->c.end();
        }

        const_iterator begin() const
        {
            return this->c.begin();
        }

        const_iterator end() const
        {
            return this->c.end();
        }
        
};

/*#include <list>

template <typename T>
class Mutantlist : public std::list<T>
{
    public:
        Mutantlist() : std::list<T>(){}
        Mutantlist(const Mutantlist& other) : std::list<T>(other){}
        Mutantlist& operator=(const Mutantlist& other)
        {
            if(this != &other)
                std::list<T>::operator=(other);
            return *this;
        }
        ~Mutantlist(){}

        typedef typename std::list<T>::iterator iterator;
        typedef typename std::list<T>::const_iterator const_iterator;

        iterator begin()
        {
            return std::list<T>::begin();
        }

        iterator end()
        {
            return std::list<T>::end();
        }

        const_iterator begin() const
        {
            return std::list<T>::begin();
        }

        const_iterator end() const
        {
            return std::list<T>::end();
        }
        
};*/



#endif