/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachkar <hlachkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 01:26:30 by hlachkar          #+#    #+#             */
/*   Updated: 2023/05/13 01:26:31 by hlachkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main(void)
{
    int a(2), b(4);
    swap<int>(a, b);
    std::cout << a << "'" << b << std::endl;
    std::cout << max<int>(a, b);
    std::cout << min<int>(a, b) << std::endl;
    return (0);
}