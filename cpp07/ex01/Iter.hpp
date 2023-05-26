/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bufallo <bufallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 01:26:56 by hlachkar          #+#    #+#             */
/*   Updated: 2023/05/18 09:04:14 by bufallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template<typename T>

void iter(T a[], int const & b, void  func(T &))
{
    int i = 0;
    while (i < b)
    {
        func(a[i]);
        i++;
    }
}

template<typename T>
void print(T &a)
{
    std::cout << a << std::endl;
}
