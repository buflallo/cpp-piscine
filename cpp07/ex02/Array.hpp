#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>


template<typename T>
class Array {
private:
    T* m_data;
    size_t m_size;

public:
    Array();

    Array(size_t size);

    ~Array();

    Array(Array<T> const &src);

    Array &operator=(Array const &rhs);

    T& operator[](size_t i);
    T const &operator[](size_t i) const;

    size_t size() const;
};

#include "Array.ipp"

#endif