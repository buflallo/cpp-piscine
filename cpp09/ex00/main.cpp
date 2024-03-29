/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachkar <hlachkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 01:39:47 by hlachkar          #+#    #+#             */
/*   Updated: 2023/05/31 01:39:48 by hlachkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "wrong number of arguments" << std::endl;
        return (1);
    }

    std::map<std::string, float> exchange_rates;
    initialize_database(exchange_rates);
    //parse the input.txt
    parse_file(av[1], exchange_rates);

    return (0);
}
