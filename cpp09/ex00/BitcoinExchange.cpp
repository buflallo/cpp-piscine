/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachkar <hlachkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 01:39:39 by hlachkar          #+#    #+#             */
/*   Updated: 2023/05/31 01:39:40 by hlachkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void test(std::map<std::string, float> const & exchange_rates, std::string const & date, float const & val)
{
    try
    {
        float ex_rate = exchange_rates.at(date);
        std::cout << "Exchange rate for " << date << ": " << ex_rate * val << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exchange rate for " << date << ": " << (--exchange_rates.lower_bound(date))->second * val << std::endl;
    }
}

void initialize_database(std::map<std::string, float> & exchange_rates)
{
    std::ifstream infile("data.csv");
    float rate;
    std::istringstream in;
    std::string date_str, line;
    std::getline(infile, line);
    while (std::getline(infile, line))
    {
        line.replace(10, 1, " ");
        in.str(line);
        in >> date_str >> rate;
        in.clear();
        exchange_rates[date_str] = rate;
    }
}

bool validate_date(std::string const & date)
{
    std::istringstream in(date);
    std::string chk;
    int year, month, day;
    char delimiter;

    if (in >> year >> delimiter >> month >> delimiter >> day) {
        if (in.fail() || delimiter != '-' || in >> chk) {
            return false;
        }
        if (year < 2009 || year > 9999 || (year == 2009 && day < 2)) {
            return false;
        }
        if (month < 1 || month > 12) {
            return false;
        }
        if (day < 1 || day > 31 || ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) || (month == 2 && (day > 29 || (year % 4 != 0 && day > 28)))) {
            return false;
        }
        return true;
    }

    return false;
}

bool validate(std::string const & date, char const & delim, float const & value, std::string const & line)
{
    if (value < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    if (value > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return false;
    }
    if (!validate_date(date) || delim != '|')
    {
        std::cout << "Error: bad input => " << line << std::endl;
        return false;
    }
    return true;
}

void parse_file(char * const & filename, std::map<std::string, float> & exchange_rates)
{
    std::string date_str, line, chk;
    float value;
    std::string::size_type pos;
    std::istringstream in;
    char delim;
    std::ifstream infile(filename);
    
    if (!infile || infile.fail()) {
        std::cerr << "Error: failed to open file " << filename << std::endl;
        return ;
    }
    std::getline(infile, line);
    if (line.empty())
    {
        std::cout << "Error: empty file." << std::endl;
        return ;
    }
    while (std::getline(infile, line))
    {
        pos = line.find(',');
        if (pos != std::string::npos)
            line.replace(pos, 1, ".", 1);
        in.str(line);
        in >> date_str >> delim >> value;
        if (!in.fail() && !(in >> chk))
        {
            if (validate(date_str, delim, value, line))
                test(exchange_rates, date_str, value);
        }
        else
            std::cout << "Error: bad input => " << line << std::endl;
        in.clear();
    }
}
