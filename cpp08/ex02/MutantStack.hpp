#ifndef MutantStack_HPP
#define MutantStack_HPP

#include <stack>
#include <iostream>
#include <vector>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack();
        MutantStack(const MutantStack<T> &copy);
        MutantStack<T> &operator=(const MutantStack<T> &copy);
        ~MutantStack();

        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin();
        iterator end();
};

#include "MutantStack.tpp"

#endif