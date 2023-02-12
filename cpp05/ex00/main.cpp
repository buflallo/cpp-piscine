/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bufallo <bufallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:17:08 by bufallo           #+#    #+#             */
/*   Updated: 2023/02/12 16:17:09 by bufallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    try{
        Bureaucrat a("test", 0);
        std::cout << a << std::endl;
    }
    catch (const std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    // try{
    //     Bureaucrat b("first",6);
    //     Bureaucrat c("second",4);
    //     std::cout << b << std::endl;
    //     b.incrementGrade();
    //     std::cout << b << std::endl;
    //     while (true)
    //     {
    //         c.incrementGrade();
    //         std::cout << c << std::endl;
    //     }
    // }
    // catch (const std::exception & e)
    // {
    //     std::cerr << e.what() << std::endl;
    // }
    return (0);
}