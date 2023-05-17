/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.ipp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachkar <hlachkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 01:27:05 by hlachkar          #+#    #+#             */
/*   Updated: 2023/05/17 22:36:22 by hlachkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
Array<T>::Array() : m_data(new T[0]), m_size(0) {}

template<typename T>
Array<T>::Array(size_t n) : m_data(new T[n]), m_size(n) {}

template<typename T>
Array<T>::~Array() {
    delete[] m_data;
}

template<typename T>
Array<T>::Array(Array const &src)
{
    *this = src;
}

template<typename T>
Array<T> &Array<T>::operator=(Array<T> const &rhs)
{
    if (this != &rhs)
    {
        this->m_size = rhs.m_size;
        if (this->m_data)
            delete[] this->m_data;
        this->m_data = new T[rhs.m_size];
        for (unsigned int i = 0; i < rhs.m_size; i++)
            this->m_data[i] = rhs.m_data[i];
    }
    return (*this);
}

template<typename T>
T& Array<T>::operator[](size_t i) {
    if (i >= m_size)
        throw std::out_of_range("index is out of range");
    return m_data[i];
}

template<typename T>
T const & Array<T>::operator[](size_t i) const{
    if (i >= m_size)
        throw std::out_of_range("index is out of range");
    return m_data[i];
}

template<typename T>
size_t Array<T>::size() const {
    return m_size;
}
