/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachkar <hlachkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 01:37:48 by hlachkar          #+#    #+#             */
/*   Updated: 2023/05/31 01:37:49 by hlachkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av) 
{
    if (ac != 2)
    {
        std::cerr << "Usage: " << av[0] << " <inverted Polish mathematical exp>" << std::endl;
        return (1);
    }
    if (!is_valid_rpn(av[1]))
    {
        std::cout << av[1] << " : THIS IS NOT A VALID RPN" << std::endl;
        return 0;
    }
    int result = calcul_rpn(av[1]);
    std::cout << result << std::endl;
    return 0;
}
