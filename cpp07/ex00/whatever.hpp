/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachkar <hlachkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 01:26:49 by hlachkar          #+#    #+#             */
/*   Updated: 2023/05/13 01:26:50 by hlachkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template<typename T>

void swap(T& a, T& b)
{
    T tmp;

    tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
T max(const T& a, const T& b)
{
    return a > b ? a : b;
}

template<typename T>
T min(const T& a, const T& b)
{
    return a < b ? a : b;
}
