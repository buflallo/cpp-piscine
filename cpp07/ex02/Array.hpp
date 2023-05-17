/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachkar <hlachkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 01:27:03 by hlachkar          #+#    #+#             */
/*   Updated: 2023/05/17 22:41:17 by hlachkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

        Array(size_t n);

        ~Array();

        Array(Array<T> const &src);

        Array<T> &operator=(Array<T> const &rhs);

        T& operator[](size_t i);
        T const &operator[](size_t i) const;

        size_t size() const;
};

#include "Array.tpp"

#endif