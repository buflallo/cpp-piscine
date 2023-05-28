template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &copy) : std::stack<T>(copy)
{}

template<typename T>
MutantStack<T> & MutantStack<T>::operator=(const MutantStack<T> &copy)
{
    std::stack<T>::operator=(copy);
    return (*this);
}

template<typename T>
MutantStack<T>::~MutantStack()
{}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return (std::stack<T>::c.begin());
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return (std::stack<T>::c.end());
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
    return (std::stack<T>::c.begin());
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cbegin() const
{
    return (std::stack<T>::c.cbegin());
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
    return (std::stack<T>::c.end());
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cend() const
{
    return (std::stack<T>::c.cend());
}


template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
    return (std::stack<T>::c.rbegin());
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
    return (std::stack<T>::c.rend());
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const
{
    return (std::stack<T>::c.rbegin());
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crbegin() const
{
    return (std::stack<T>::c.crbegin());
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
    return (std::stack<T>::c.rend());
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crend() const
{
    return (std::stack<T>::c.crend());
}
