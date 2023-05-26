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
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

        iterator begin();
        iterator end();

        const_iterator begin() const;
        const_iterator cbegin() const;
        const_iterator end() const;
        const_iterator cend() const;

        reverse_iterator rbegin();
        reverse_iterator rend();

        const_reverse_iterator rbegin() const;
        const_reverse_iterator crbegin() const;
        const_reverse_iterator rend() const;
        const_reverse_iterator crend() const;
};

#include "MutantStack.tpp"

#endif