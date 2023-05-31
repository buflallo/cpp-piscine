/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachkar <hlachkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 01:39:43 by hlachkar          #+#    #+#             */
/*   Updated: 2023/05/31 01:39:44 by hlachkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP_
#define BITCOINEXCHANGE_HPP_

#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <sstream>

void test(std::map<std::string, float> const & exchange_rates, std::string const & date, float const & val);
void initialize_database(std::map<std::string, float> &exchange_rates);
bool validate_date(std::string const &date);
bool validate(std::string const & date, char const & delim, float const & value, std::string const & line);
void parse_file(char * const & filename, std::map<std::string, float> & exchange_rates);

#endif
