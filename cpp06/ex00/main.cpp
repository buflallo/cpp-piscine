/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bufallo <bufallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:05:23 by hlachkar          #+#    #+#             */
/*   Updated: 2023/05/08 19:43:12 by bufallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

typedef struct pp{
    int a;
    int b;
} op;

typedef struct pep{
    int a;
    char* b;
} pos;

int main()
{
    // ScalarConverter test;
    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);

    // if (ac == 2)
    //     test.convert(av[1]);
    op a;
    a.b = 97;
    a.a = std::numeric_limits<int>::max();
    pos *b;
    b = static_cast<pos*>(&a);
    std::cout << b->b << std::endl;
    // char b = static_cast<char>(a);
    // std::cout << "size int: " << sizeof(a) << " size char: " << sizeof(static_cast<char>(a)) << std::endl;
    return (0);
}