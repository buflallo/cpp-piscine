/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachkar <hlachkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:05:23 by hlachkar          #+#    #+#             */
/*   Updated: 2023/04/15 00:14:53 by hlachkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    ScalarConverter test;
    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);

    if (ac == 2)
        test.convert(av[1]);
    return (0);
}